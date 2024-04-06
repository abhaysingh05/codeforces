#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long
const int INF = (int)1e9;
const int mod = INF + 7;
/**************************************************************************************/

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    sort(all(v));.
    int ans = 0;
    for (int i = 1; i < x; i++) {
        if (v[i] - v[0] >= 2) ans++;
    }
    if (ans) ans++;
    cout << ans << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}