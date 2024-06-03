#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 998244353;

// @author: ZhockDen

int popcount(int x) {
    return __builtin_popcount(x);
}

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t n, m;
    cin >> n >> m;
    int64_t ans = 0;
    for (int k = 0; k <= n; ++k) {
        int km = k & m;
        ans += popcount(km);
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans % mod << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}