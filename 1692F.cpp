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
    vector<int> V(n);
    for (auto &ele : V) cin >> ele;
    vector<int> C(10, 0);
    for (int i = 0; i < n; i++) {
        V[i] %= 10;
        if (C[V[i]] == 3) continue;
        C[V[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (C[i] == 0) continue;
        int x = i;
        C[i]--;
        for (int j = 0; j < 10; j++) {
            if (C[j] == 0) continue;
            int y = j;
            C[j]--;
            for (int k = 0; k < 10; k++) {
                if (C[k] == 0) continue;
                int z = k;
                if (x + y + z == 3 || x + y + z == 13 || x + y + z == 23) {
                    cout << "YES\n";
                    return;
                }
            }
            C[j]++;
        }
        C[i]++;
    }
    cout << "NO\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}