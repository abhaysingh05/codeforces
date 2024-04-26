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
    vector<int> arr(n);
    for (auto &e : arr) cin >> e;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        arr[i] -= i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mp[arr[i]];
        mp[arr[i]]++;
    }
    cout << ans << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}