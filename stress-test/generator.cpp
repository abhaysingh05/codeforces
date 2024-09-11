#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

// @author: ZhockDen

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rnd(int64_t l = 0, int64_t r = 1E9) {
    if (l > r) swap(l, r);
    return std::uniform_int_distribution<int64_t>(l, r)(rng);
    // return std::uniform_real_distribution<long double>(l, r)(rng);
}

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";
    int64_t t = rnd(1, 1);
    cout << t << "\n";
    while (t--) {
        int n = rnd(1, 6);
        cout << n << "\n";
        // Generate edges
        vector<pair<int, int>> edges;
        for (int i = 2; i <= n; i++) {
            int parent = rnd(1, i - 1);
            edges.push_back({parent, i});
        }

        // Output edges
        for (const auto &edge : edges) {
            cout << edge.first << " " << edge.second << "\n";
        }
        for (int i = 0; i < n; i++) {
            int num = rnd(0, 2);
            if (num == 2)
                cout << '?';
            else
                cout << num;
        }
        cout << "\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}