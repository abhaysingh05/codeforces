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

    int n, k, curr = 1;
    cin >> n >> k;
    k--;
    vector<int> cows(n);
    for (auto &e : cows) cin >> e;
    if (k != 0) {
        curr = 0;
    }
    int ans = 0;
    for (int i = curr; i < n; i++) {
        if (cows[i] < cows[k])
            ans++;
        else
            break;
    }
    cout << ans << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}