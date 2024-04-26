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
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    while (k--) {
        int x;
        cin >> x;
        int l = -1;
        int r = n;
        int m;
        while (r > l + 1) {
            m = (l + r) / 2;
            if (a[m] < x)
                l = m;
            else
                r = m;
        }
        cout << r + 1 << "\n";
    }
}

int32_t main() {

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}