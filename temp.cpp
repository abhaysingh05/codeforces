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

    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (auto &e : v) cin >> e;
    sort(v.begin(), v.end());
    int cnt = 1;
    int val = v[0];
    int curr = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (v[i] == v[i - 1]) {
            curr++;
            if (curr > cnt) {
                cnt = curr;
                val = v[i];
            }
        } else {
            curr = 1;
        }
    }
    if (cnt >= n) {
        cout << 0 << "\n";
        return;
    }
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++) {
        mp[v[i]]++;
    }
    vector<pair<int, int>> vvp;
    for (auto &[x, y] : mp) {
        vvp.push_back({x, y});
    }
    sort(vvp.begin(), vvp.end(), [&](auto a, auto b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    for (auto &[x, y] : vvp) cout << x << " " << y << "\n";
    int sum = 0;
    int mn = INT32_MAX;
    int mx = INT32_MIN;
    for (int i = 0; i < vvp.size(); i++) {
        sum += vvp[i].second;
        mn = min(mn, vvp[i].first);
        mx = max(mx, vvp[i].first);
        if (sum >= n) {
            break;
        }
    }
    int mnu = INT32_MAX;
    int mxu = INT32_MIN;
    int sumu = 0;
    for (int i = vvp.size() - 1; i >= 0; i--) {
        sumu += vvp[i].second;
        mnu = min(mnu, vvp[i].first);
        mxu = max(mxu, vvp[i].first);
        if (sumu >= n) {
            break;
        }
    }
    cout << (mx - mn) * (mxu - mnu) << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}