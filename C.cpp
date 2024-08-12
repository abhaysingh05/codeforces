#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

// Function to compute the maximum score achievable
void runCase(int &testCase) {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n), b(n);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    vector<int64_t> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    int64_t median_index = (n - 1) / 2;

    int64_t max_score = 0;
    for (int64_t i = 0; i < n; ++i) {
        if (b[i] == 1) {
            int64_t left = a[i], right = 1e18, best = 0;
            while (left <= right) {
                int64_t mid = (left + right) / 2;
                vector<int64_t> temp = a;
                temp[i] = mid;
                sort(temp.begin(), temp.end());
                int64_t median = temp[median_index];
                if (mid + median <= max_score) {
                    left = mid + 1;
                } else {
                    best = mid;
                    right = mid - 1;
                }
            }
            max_score = max(max_score, best + sorted_a[median_index] + k);
        } else {
            vector<int64_t> temp = a;
            sort(temp.begin(), temp.end());
            int64_t median = temp[median_index];
            max_score = max(max_score, a[i] + median);
        }
    }
    cout << max_score << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        runCase(i);
    }

    return 0;
}
