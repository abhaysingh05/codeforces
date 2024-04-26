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

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int x = 0; x <= n; x += a) {
        for (int y = 0; y <= n - x; y += b) {
            double z = ((float)n - x - y) / c;
            if (ceil(z) == floor(z)) ans = max(ans, x / a + y / b + (int)floor(z));
        }
    }
    cout << ans << "\n";
}

int32_t main() {

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}