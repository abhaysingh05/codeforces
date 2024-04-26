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

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto &e : arr) cin >> e;
    vector<int> mx(n);
    vector<int> pfs(n);
    pfs[0] = arr[0];
    mx[0] = arr[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], arr[i]);
        pfs[i] = pfs[i - 1] + arr[i];
    }
    while (q--) {
        int ans = 0;
        int x;
        cin >> x;
        auto it2 = upper_bound(all(mx), x);
        if (it2 == mx.begin()) {
            cout << ans << " ";
            continue;
        }
        it2--;
        int k = it2 - mx.begin();
        ans = pfs[k];
        cout << ans << " ";
    }
    cout << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}