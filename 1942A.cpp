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
    if (n == k) {
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << "\n";
    } else if (k == 1) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}