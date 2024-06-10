#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int z = 1;
    for (int i = 0; i < n; i++) {
        z = lcm(z, k[i]);
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += z / k[i];
    }
    int summm = 0;
    vector<int> ress;
    if (suma < z) {
        for (int i = 0; i < n; i++) {
            summm += z / k[i];
            ress.push_back(z / k[i]);
        }
    } else {
        cout << -1 << "\n";
        return;
    }
    int check = false;
    for (int i = 0; i < n; i++) {
        if (summm > k[i] * ress[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}