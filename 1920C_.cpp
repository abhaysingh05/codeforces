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
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.pb(i);
            if (i != n / i) divisors.pb(n / i);
        }
    }
    sort(all(divisors));
    // for (auto &e : divisors) cout << e << " ";
    // cout << "\n";
    int ans = 0;
    for (auto &div : divisors) {
        int m = 2;
        bool flag = false;
        for (int i = 0; i < n / div; i++) {
            int val = v[i] % m;
            for (int j = i; j < n; j += n/div) {
                if (v[j] % m != val) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) ans++;
    }
    cout << ans << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}