#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long
const int INF = (int)1e9;
const int mod = INF + 7;
const double eps = 1e-6;
const int N = 1e3 + 10;
/**************************************************************************************/
vector<vector<int>> graph(N);
vector<bool> vis(N, false);
int n;
bool check = false;
struct circle {
    int x;
    int y;
    int r;
};
bool isTangent(circle c1, circle c2) {
    return (((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y)) == ((c1.r + c2.r) * (c1.r + c2.r)));
}
void dfs(int vertex, int parent) {
    vis[vertex] = true;
    for (auto child : graph[vertex]) {
        if (vis[child] && child == parent)
            continue;
        if (vis[child]) {
            check = true;
            return;
        }
        dfs(child, vertex);
    }
}
void solve1(int &answer) {
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        dfs(i, 0);
        if (check == true) {
            break;
        }
    }
    if (check) {
        answer = 0;
    } else
        answer = 1;
}
bool vis1[N];
void dfs1(int vertex1) {
    vis1[vertex1] = true;
    for (auto child : graph[vertex1]) {
        if (vis1[child])
            continue;
        dfs1(child);
    }
}
void solve2(int &answer) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis1[i])
            continue;
        dfs1(i);
        ans++;
        if (ans > 1) {
            answer = 1;
            return;
        }
    }
    answer = 0;
}
void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";
    int answer1 = 0;
    int answer2 = 0;
    cin >> n;
    vector<circle> arr(n);
    for (auto &e : arr) cin >> e.x >> e.y >> e.r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (isTangent(arr[i], arr[j])) {
                graph[i].pb(j);
            }
        }
    }
    solve1(answer1);
    solve2(answer2);
    if (!answer1 && !answer2) {
        cout << "NO\n";
        return;
    }
    if (answer1 && answer2) {
        cout << "YES\n";
        return;
    }
    if (!answer1) {
        cout << "NO\n";
        return;
    }
    if (answer2) {
        cout << "YES\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}