#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

// #ifdef LOCAL
// #include "debug.h"
// #else
// #define dbg(...)
// #endif

// @author: ZhockDen

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";
// 1
// 5 5
// 8 1 5 8 9
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> v(n);
    for (auto &e : v) cin >> e;
    int64_t i = 0, j = 0, ans = 0, curr = 0;
    int64_t cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += v[k];
                if (sum > x) sum = 0;
            }
            if (sum != 0) {

                ans++;
            }
            // if (sum == 0 && v[j] <= x) cout << i << " " << j << "\n";
        }
    }
    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}