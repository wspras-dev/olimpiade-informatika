#include <iostream>
using namespace std;

int main() {
    // Optimasi input/output pada C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    long long min_pangkat = 1e18; // Inisialisasi dengan nilai yang sangat besar
    long long best_p = -1;

    // Faktorisasi prima N dari 2 hingga sqrt(N)
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            long long pangkat = 0;
            // Hitung ada berapa pangkat untuk faktor prima i
            while (N % i == 0) {
                pangkat++;
                N /= i;
            }
            
            // Jika pangkat yang ditemukan lebih kecil dari rekor minimum saat ini
            if (pangkat < min_pangkat) {
                min_pangkat = pangkat;
                best_p = i;
            }
        }
    }

    // Jika N masih bersisa lebih dari 1, maka sisa N tersebut adalah bilangan prima
    // Pangkatnya pasti tepat 1.
    if (N > 1) {
        if (1 < min_pangkat) {
            best_p = N;
        }
        // Catatan: Jika min_pangkat sudah sama dengan 1 dari loop sebelumnya, 
        // kita tidak menimpa best_p karena kita harus memilih P yang paling kecil.
        // Faktor yang didapat di dalam loop pasti lebih kecil dari sisa N.
    }

    // Cetak tipe telur (faktor prima) yang terpilih
    cout << best_p << "\n";

    return 0;
}
