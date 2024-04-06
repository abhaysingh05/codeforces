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

    int x;
    cin >> x;
    if (x == 1) {
        cout << "yoink a\nyoink b\n*slaps a on top of b *\nyeet b\ngo touch some grass\n";
    }
    if (x == 2) cout << "yoink a\nbruh b is lowkey just 0\nrip this b fell off by a\nvibe check a ratios b\nsimp for 7\nbruh a is lowkey just b\nyeet a\ngo touch some grass\n";
    if (x = = 3) cout << "yoink n\nyoink a\nbruh m is lowkey just a[0]\nbruh i is lowkey just 1\nvibe check n ratios i\nsimp for 9\nyeet m\ngo touch some grass\nvibe check a[i] ratios m\nbruh m is lowkey just a[i]\n*slaps 1 on top of i*\nsimp for 5\n";
    if (x == 4) cout << "yoink n\nyoink a\nyoink k\nyoink i\nyoink j\nyoink m\nif n is lowkey just 0\n   go touch some grass\nif n is lowkey just 1\n   yeet a\nsimp for 7\nbruh a is lowkey just 0\nrip this a fell off by b\nvibe check b ratios 0\nyeet b\nif i is lowkey just n\n   go touch some grass\nsimp for 5\n";
}

int32_t main() {

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}