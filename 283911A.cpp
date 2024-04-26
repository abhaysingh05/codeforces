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
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    while (k--) {
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        int m;
        bool ans = false;
        while (r - l + 1 >= 1) {
            m = (l + r) / 2;
            if (V[m] < x) {
                l = m + 1;
            } else if (V[m] > x) {
                r = m - 1;
            } else {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}

int32_t main() {

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}