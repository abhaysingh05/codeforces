#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
constexpr int inf = (int)1e18;
constexpr int mod = 1e9 + 7;
/**************************************************************************************/

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    int cntpf[n][32][2];
    int cntsf[n][32][2];
    for (int i = 0; i < n; i++) {
        int k = n - i - 1;
        for (int j = 0; j < 32; j++) {
            int bit = a[i] & (1 << j);
            if (bit) {
                cntpf[i][j][1] = (i - 1 < 0 ? 0 : cntpf[i - 1][j][0]) + 1;
                cntpf[i][j][0] = (i - 1 < 0 ? 0 : cntpf[i - 1][j][1]);
                cntsf[k][j][1] = (k + 1 < n ? cntsf[k + 1][j][0] : 0) + 1;
                cntsf[k][j][0] = (k + 1 < n ? cntsf[k + 1][j][1] : 0);
            } else {
                cntpf[i][j][0] = (i - 1 < 0 ? 0 : cntpf[i - 1][j][0]) + 1;
                cntpf[i][j][1] = (i - 1 < 0 ? 0 : cntpf[i - 1][j][1]);
                cntsf[k][j][0] = (k + 1 < n ? cntsf[k + 1][j][0] : 0) + 1;
                cntsf[k][j][1] = (k + 1 < n ? cntsf[k + 1][j][1] : 0);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            ans += (i - 1 < 0 ? 1 : cntpf[i - 1][j][0]) * (i + 1 < n ? cntsf[i + 1][j][1] : 0) + (i - 1 < 0 ? 0 : cntpf[i - 1][j][1]) * (i + 1 < n ? cntsf[i + 1][j][0] : 1);
        }
    }
    cout << ans << "\n";
}

int32_t main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}