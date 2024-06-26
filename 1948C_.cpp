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
    string s1, s2;
    cin >> s1 >> s2;
    if (n & 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s1[i] == '<' && s2[i - 1] == '<') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}