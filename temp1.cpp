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

    int n, k;
    cin >> n >> k;
    k--;
    vector<int> arr(n);
    for (auto &e : arr) cin >> e;
    int mxi = 0;
    for (int i = 0; i <= k; i++) {
        if (arr[i] > arr[mxi]) {
            mxi = i;
        }
    }
    swap(arr[k], arr[mxi]);
    int val = arr[mxi];
    int id = mxi;
    for (int i = 0; i < n; i++) {
        if (arr[i] > val) {
            id = i;
            break;
        }
    }
    if (mxi == 0) id--;
    cout << id - mxi << "\n";
}

int32_t main() {

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}