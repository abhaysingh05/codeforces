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

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t n;
    cin >> n;
    vector<int64_t> v(n);
    for (auto &e : v) cin >> e;
    function<int64_t(int64_t, int64_t)> fun = [&](int64_t i, int64_t j) -> int64_t {
        if (i == n) return 0;
        int64_t way1 = v[i] + j + fun(i + 1, j + v[i]);
        int64_t way2 = abs(v[i] + j) + fun(i + 1, abs(v[i] + j));
        return max(way1, way2);
    };
    cout << fun(0, 0) << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}