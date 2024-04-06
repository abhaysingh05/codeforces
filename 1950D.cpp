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
    vector<int> v = {0, 1, 10, 11, 100, 110, 101, 111, 1000, 1100, 1010, 1110, 1001, 1101, 1011, 1111, 10000, 11000, 10100, 11100, 10010, 11010, 10110, 11110, 10001, 11001, 10101, 11101, 10011, 11011, 10111, 11111, 100000, 110000, 101000, 111000, 100100, 110100, 101100, 111100, 100010, 110010, 101010, 111010, 100110, 110110, 101110, 111110, 100001, 110001, 101001, 111001, 100101, 110101, 101101, 111101, 100011, 110011, 101011, 111011, 100111, 110111, 101111, 111111};
    int n;
    cin >> n;
    if (n == 0 || n == 1) {
        cout << "YES\n";
        return;
    }
    sort(all(v), greater<int>());
    while (n) {
        if (n == 0 || n == 1) {
            cout << "YES\n";
            return;
        }
        bool flag = false;
        for (auto e : v) {
            if (e != 0 && e != 1 && n % e == 0) {
                flag = true;
                n /= e;
                break;
            }
        }
        if (flag == false) {
            cout << "NO\n";
            return;
        }
    }
    if (n == 0) {

        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}