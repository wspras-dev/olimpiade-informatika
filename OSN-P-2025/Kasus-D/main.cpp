#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi bantuan untuk mengambil jumlah telur maksimal dari sisa blok yang ada
long long get_max(long long forced_sum, long long allowed, vector<long long>& avail) {
    if (allowed < 0) return 0; // Jika jumlah operasi tidak cukup, skenario ini tidak valid
    
    long long sum = forced_sum;
    
    // Sortir blok sisa secara menurun (descending) untuk mendapatkan blok terpanjang
    sort(avail.rbegin(), avail.rend());
    
    // Ambil maksimal `allowed` blok terbesar (atau semua jika allowed melebihi ukuran)
    long long take = min(allowed, (long long)avail.size());
    for (long long i = 0; i < take; i++) {
        sum += avail[i];
    }
    
    return sum;
}

int main() {
    // Optimasi Input/Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long K;
    if (!(cin >> N >> K)) return 0;
    
    string S;
    cin >> S;

    // Kumpulkan panjang semua blok 'B' yang berurutan
    vector<long long> L;
    long long current_len = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'B') {
            current_len++;
        } else {
            if (current_len > 0) {
                L.push_back(current_len);
                current_len = 0;
            }
        }
    }
    if (current_len > 0) {
        L.push_back(current_len);
    }

    int M = L.size();
    
    // Kasus Dasar: Jika tidak ada varian Balado sama sekali
    if (M == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Cek apakah string murni diawali atau diakhiri dengan 'B'
    bool has_prefix = (S[0] == 'B');
    bool has_suffix = (S[N - 1] == 'B');

    long long ans = 0;
    long long allowed = K - 1; // Formula konstan untuk operasi ekstra

    // ----------------------------------------------------
    // Skenario A: Tanpa mengasumsikan bebas dari tepi mana pun
    // ----------------------------------------------------
    if (allowed >= 0) {
        vector<long long> avail = L;
        ans = max(ans, get_max(0, allowed, avail));
    }

    // ----------------------------------------------------
    // Skenario B: Mengasumsikan blok pertama bebas biaya prefix
    // ----------------------------------------------------
    if (has_prefix && M >= 1 && allowed >= 0) {
        vector<long long> avail;
        for (int i = 1; i < M; i++) avail.push_back(L[i]);
        ans = max(ans, get_max(L[0], allowed, avail));
    }

    // ----------------------------------------------------
    // Skenario C: Mengasumsikan blok terakhir bebas biaya suffix
    // ----------------------------------------------------
    if (has_suffix && M >= 1 && allowed >= 0) {
        vector<long long> avail;
        for (int i = 0; i < M - 1; i++) avail.push_back(L[i]);
        ans = max(ans, get_max(L[M - 1], allowed, avail));
    }

    // ----------------------------------------------------
    // Skenario D: Blok pertama & terakhir bebas biaya (hanya jeda)
    // ----------------------------------------------------
    if (has_prefix && has_suffix && M >= 1) {
        if (M == 1) {
            // Jika seluruh string dipenuhi 'B', tidak ada jeda yang perlu dihapus (Cost 0)
            ans = max(ans, L[0]);
        } else {
            if (allowed >= 0) {
                vector<long long> avail;
                for (int i = 1; i < M - 1; i++) avail.push_back(L[i]);
                ans = max(ans, get_max(L[0] + L[M - 1], allowed, avail));
            }
        }
    }

    // Tampilkan hasil optimal dari keempat skenario
    cout << ans << "\n";

    return 0;
}