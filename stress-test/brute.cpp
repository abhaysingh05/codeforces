#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

// @author: ZhockDen
vector<int64_t> pfs(2e5 + 1, 0);
auto log3 = [](int64_t x) {
    int64_t res = 0;
    while (x > 0) {
        res++;
        x /= 3;
    }
    return res;
};
void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t l, r;
    cin >> l >> r;
    int64_t ans = 0;
    ans += log3(l);
    ans += pfs[r] - (l <= 0 ? 0 : pfs[l - 1]);
    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int64_t i = 1; i <= 2e5; i++) {
        pfs[i] = pfs[i - 1] + log3(i);
    }

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}