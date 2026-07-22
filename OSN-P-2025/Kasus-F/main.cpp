#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string S1, S2;
    cin >> S1 >> S2;

    // Mengubah index string menjadi 1-based dengan padding
    S1 = " " + S1;
    S2 = " " + S2;

    vector<long long> M1(N + 1), M2(N + 1);
    for (int i = 1; i <= N; ++i) cin >> M1[i];
    for (int i = 1; i <= N; ++i) cin >> M2[i];

    int lastA = 0, lastB = 0;
    for (int i = 1; i <= N; ++i) {
        if (S1[i] == 'A' || S2[i] == 'A') lastA = max(lastA, i);
        if (S1[i] == 'B' || S2[i] == 'B') lastB = max(lastB, i);
    }

    int mid = min(lastA, lastB);

    // Cek jika perselisihan PASTI terjadi di zona perpecahan (split region)
    for (int i = 1; i <= mid; ++i) {
        if (S2[i] == 'A') { cout << -1 << "\n"; return 0; } // Ayam berada di wilayah mutlak Bebek
        if (S1[i] == 'B') { cout << -1 << "\n"; return 0; } // Bebek berada di wilayah mutlak Ayam
    }

    // Prefix sum untuk menghitung nilai kebecekan di zona split
    vector<long long> PrefA(N + 1, 0), PrefB(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        PrefA[i] = PrefA[i - 1] + M1[i];
        PrefB[i] = PrefB[i - 1] + M2[i];
    }

    // DP State: menyimpan biaya minimum dari cell(baris, kolom) menuju titik keluar di (baris_hewan, mid)
    vector<long long> distA1(N + 1, 0), distA2(N + 1, 0);
    vector<long long> distB1(N + 1, 0), distB2(N + 1, 0);

    // DP untuk jalur Ayam yang bermanuver leluasa di region kanan (jika ada)
    if (lastA > mid) {
        distA1[mid] = M1[mid];
        distA2[mid] = INF; // Ayam tidak boleh masuk dari baris 2 di batas split
        for (int c = mid + 1; c <= lastA; ++c) {
            long long t1 = (distA1[c - 1] == INF) ? INF : M1[c] + distA1[c - 1];
            long long t2 = (distA2[c - 1] == INF) ? INF : M2[c] + distA2[c - 1];
            
            distA1[c] = t1;
            if (t2 != INF) distA1[c] = min(distA1[c], M1[c] + t2);
            
            distA2[c] = t2;
            if (t1 != INF) distA2[c] = min(distA2[c], M2[c] + t1);
        }
    }

    // DP untuk jalur Bebek yang bermanuver leluasa di region kanan (jika ada)
    if (lastB > mid) {
        distB2[mid] = M2[mid];
        distB1[mid] = INF; // Bebek tidak boleh masuk dari baris 1 di batas split
        for (int c = mid + 1; c <= lastB; ++c) {
            long long t1 = (distB1[c - 1] == INF) ? INF : M1[c] + distB1[c - 1];
            long long t2 = (distB2[c - 1] == INF) ? INF : M2[c] + distB2[c - 1];
            
            distB1[c] = t1;
            if (t2 != INF) distB1[c] = min(distB1[c], M1[c] + t2);
            
            distB2[c] = t2;
            if (t1 != INF) distB2[c] = min(distB2[c], M2[c] + t1);
        }
    }

    // Kalkulasi Total nilai kerisihan untuk setiap hewan individual
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        if (S1[i] == 'A') {
            if (i <= mid) total_cost += PrefA[i];
            else total_cost += distA1[i] + PrefA[mid - 1];
        }
        if (S2[i] == 'A') { // (Hanya bisa terjadi di > mid karena di <= mid sudah difilter keluar -1)
            total_cost += distA2[i] + PrefA[mid - 1];
        }
        if (S1[i] == 'B') { // (Hanya bisa terjadi di > mid karena di <= mid sudah difilter keluar -1)
            total_cost += distB1[i] + PrefB[mid - 1];
        }
        if (S2[i] == 'B') {
            if (i <= mid) total_cost += PrefB[i];
            else total_cost += distB2[i] + PrefB[mid - 1];
        }
    }

    cout << total_cost << "\n";
    return 0;
}
