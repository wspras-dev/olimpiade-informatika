#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
vector<int> tree_max;

// Fungsi untuk memperbarui Segment Tree (Point Update)
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree_max[node] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
        update(2 * node, l, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, r, idx, val);
    }
    tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
}

// Fungsi untuk mencari nilai DP terbesar pada rentang (Range Max Query)
int query(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return -INF;
    if (ql <= l && r <= qr) return tree_max[node];
    
    int mid = l + (r - l) / 2;
    return max(query(2 * node, l, mid, ql, qr),
               query(2 * node + 1, mid + 1, r, ql, qr));
}

int main() {
    // Optimasi Input/Output agar tidak Time Limit Exceeded (TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    long long K;
    if (!(cin >> N >> M >> K)) return 0;

    // Membaca array dari indeks 1 (1-based index)
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Mengurutkan bambu agar pengelompokan sub-array optimal
    sort(A.begin() + 1, A.end());

    // Inisialisasi Segment Tree dan array DP dengan nilai -INF (tidak mungkin dicapai)
    tree_max.assign(4 * (N + 1), -INF);
    vector<int> dp(N + 1, -INF);

    // Base case: 0 bambu berarti 0 ikat
    dp[0] = 0;
    update(1, 0, N, 0, 0);

    for (int i = 1; i <= N; ++i) {
        // Binary search untuk mencari indeks j+1 terkecil dimana A[j+1] >= A[i] - K
        int L_i = lower_bound(A.begin() + 1, A.begin() + i + 1, A[i] - K) - A.begin();

        // Rentang nilai 'j' yang valid untuk menjadi ujung partisi sebelumnya
        int left_bound = L_i - 1;
        int right_bound = i - M;

        // Jika rentang batas valid, cari nilai DP terbesar di antara rentang tersebut
        if (left_bound <= right_bound && right_bound >= 0) {
            int max_prev = query(1, 0, N, left_bound, right_bound);
            
            // Jika valid (ada cara menyusun sebelumnya), maka ikat bertambah 1
            if (max_prev != -INF) {
                dp[i] = max_prev + 1;
            }
        }

        // Masukkan state dp[i] saat ini ke dalam Segment Tree agar bisa di-query kedepannya
        if (dp[i] != -INF) {
            update(1, 0, N, i, dp[i]);
        }
    }

    // Output -1 jika tidak memungkinkan seluruh bambu dipartisi, jika mungkin, keluarkan dp[N]
    if (dp[N] == -INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[N] << "\n";
    }

    return 0;
}