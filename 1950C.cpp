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
    string s;
    cin >> s;
    int hours, minutes;
    string hour, minute;
    hour = s.substr(0, 2);
    hours = stoi(hour);
    minute = s.substr(3, 2);
    minutes = stoi(minute);

    string period;
    if (hours >= 12) {
        period = "PM";
        if (hours > 12) {
            hours -= 12;
        }
    } else {
        period = "AM";
        if (hours == 0) {
            hours = 12;
        }
    }

    cout << right <<setfill(' ') << setw(2) << hours << ":" << setw(2) << minutes << " " << period << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}