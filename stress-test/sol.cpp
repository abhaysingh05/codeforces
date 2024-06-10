#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

// @author: ZhockDen

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int64_t n;
    cin >> n;
    vector<int64_t> v(n);
    for (auto &e : v) cin >> e;
    int64_t l = n;
    int64_t r = 2e10;
    int64_t ans = -1;
    auto ok = [&](int64_t x) -> int64_t {
        vector<int64_t> X(n);
        for (int i = 0; i < n; i++) {
            X[i] = 1 + x / v[i];
        }
        int64_t sum = accumulate(X.begin(), X.end(), 0LL);
        if (sum > x) return 1;
        if (sum < x) return -1;
        return 0;
    };
    bool flag = false;
    while (l <= r) {
        int64_t mid = (l + r) / 2;
        if (ok(mid) == 0) {
            flag = true;
            ans = mid;
            break;
        }
        if (ok(mid) == 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (!flag) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ress;
    int summm = 0;
    for (int i = 0; i < n; i++) {
        summm += 1 + ans / v[i];
        ress.push_back(1 + ans / v[i]);
    }
    int check = false;
    for (int i = 0; i < n; i++) {
        if (summm > v[i] * ress[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}