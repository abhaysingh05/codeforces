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
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    vector<int> mex(n+1);
    mex[0] = 0;
    for (auto &e : v) {
        
        if (e > 0)
            cout << mex++ << " ";
        else
            cout << mex - e << " ";
    }
    cout << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}