#include <bits/stdc++.h>
using namespace std;

void solve(int l, int r) {
    // Calculate s1
    int x = log(l + 1) / log(3) + 1;
    int s1 = x;
    s1 = s1 + log(l) / log(3) + x + 1;

    // Loop to add values to s1
    for (int i = 2; i <= r - l; i++) {
        s1 = s1 + log(l + i) / log(3) + 1;
    }

    // Calculate s2
    int y = floor(log(l) / log(3) + 1);
    int s2 = y;
    s2 = s2 + log(l + 1) / log(3) + y + 1;

    // Loop to add values to s2
    for (int i = 2; i <= r - l; i++) {
        s2 = s2 + log(l + i) / log(3) + 1;
    }

    // Output the minimum of s1 and s2
    cout << fmin(s1, s2) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}