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

    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    cin >> k;
    while (k--) {
        int lv, rv, l, r, m;
        cin >> lv >> rv;
        l = 0;
        r = n - 1;
        int lvv = 0, rvv = n - 1;
        while (r > l + 1) {
            m = (l + r) / 2;
            if (a[m] >= lv) {
                l = m;
            } else {
                r = m;
            }
        }
        lvv = r;
        l = 0;
        r = n - 1;
        while (r > l + 1) {
            m = (l + r) / 2;
            if (a[m] <= rv) {
                l = m;
            } else {
                r = m;
            }
        }
        rvv = l;
        cout << rvv - lvv + 1 << " ";
    }
}

int32_t main() {

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}