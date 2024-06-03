#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 998244353;

// @author: ZhockDen

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t n, m;
    cin >> n >> m;
    int64_t ans = 0;
    for (int64_t i = 0; i < 32; ++i) {
        if (m & (1 << i)) {
            int64_t b = ((n + 1) / (1LL << (i + 1))) * (1LL << i);
            int64_t temp = (n + 1) % (1LL << (i + 1));
            b += max(0LL, temp - (1LL << i));
            ans = (ans + b) % mod;
        }
    }
    cout << ans%mod << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}