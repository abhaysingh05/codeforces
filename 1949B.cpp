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
    vector<int> brr(n);
    for (auto &e : brr) cin >> e;
    sort(all(arr));
    sort(all(brr));
    // for (auto &e : brr) cout << e << " ";
    // cout << "\n";
    int val = INT_MIN;
    for (int i = 0; i < n; i++) {
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, abs(arr[j] - brr[(i + j) % n]));
        }
        val = max(val, ans);
    }
    cout << val << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}