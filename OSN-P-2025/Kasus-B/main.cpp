#include <iostream>
using namespace std;

int main() {
    // Optimasi input/output pada C++ untuk mempercepat eksekusi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, P, L;
    
    // Membaca masukan
    if (!(cin >> N >> P >> L)) return 0;

    // Batas bawah ukuran S (minimal 1)
    long long low = 1;
    // Batas atas ukuran S yang paling aman (3 Miliar, masuk dalam tipe long long)
    // S maks terjadi saat N = 10^12, P = 2000, L = 2000 -> S = 2.000.000.000
    long long high = 3000000000LL; 
    long long ans = high;

    // Algoritma Binary Search
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        long long baris = mid / P;
        long long kolom = mid / L;

        // Jika S terlalu kecil sehingga kardus tidak muat secara dimensi
        if (baris == 0 || kolom == 0) {
            low = mid + 1;
        } else {
            // Mencegah OVERFLOW dengan trik pembagian ceil: 
            // baris * kolom >= N identik dengan baris >= ceil(N / kolom)
            if (baris >= (N + kolom - 1) / kolom) {
                ans = mid;         // mid cukup besar, simpan sebagai calon jawaban
                high = mid - 1;    // coba cari ukuran gudang yang lebih kecil lagi
            } else {
                low = mid + 1;     // mid terlalu kecil, harus diperbesar
            }
        }
    }

    // Mencetak output jawaban terkecil
    cout << ans << "\n";

    return 0;
}
