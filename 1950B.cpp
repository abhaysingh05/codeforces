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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char a = '#', b = '.';
        if (i & 1) {
            for (int j = 1; j <= n; j++) {
                cout << a;
                cout << a;
                swap(a, b);
            }
            cout << "\n";
            a = '#';
            b = '.';
            for (int j = 1; j <= n; j++) {
                cout << a;
                cout << a;
                swap(a, b);
            }
        } else {
            swap(a, b);
            for (int j = 1; j <= n; j++) {
                cout << a;
                cout << a;
                swap(a, b);
            }
            a = '.';
            b = '#';
            cout << "\n";
            for (int j = 1; j <= n; j++) {
                cout << a;
                cout << a;
                swap(a, b);
            }
        }
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}