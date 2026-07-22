#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    if (!(cin >> S)) return 0;

    int cnt_p_remaining = 0;
    int len = S.length(); // Simpan panjang string ke variabel

    // Iterasi gaya C++98 untuk menghitung total huruf 'P'
    for (int i = 0; i < len; ++i) {
        if (S[i] == 'P') {
            cnt_p_remaining++;
        }
    }

    int cnt_o = 0;
    int cnt_s = 0;
    int cnt_n = 0;
    int max_len = -1;

    // Iterasi gaya C++98 dari kiri ke kanan
    for (int i = 0; i < len; ++i) {
        char c = S[i]; // Ambil karakter pada indeks ke-i
        
        if (c == 'P') {
            if (cnt_o > 0 && cnt_s > 0 && cnt_n > 0) {
                int current_len = cnt_o + cnt_s + cnt_n + cnt_p_remaining;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
            cnt_p_remaining--;
        } 
        else if (c == 'O') {
            cnt_o++;
        } 
        else if (c == 'S') {
            cnt_s++;
        } 
        else if (c == 'N') {
            cnt_n++;
        }
    }

    cout << max_len << "\n";

    return 0;
}
