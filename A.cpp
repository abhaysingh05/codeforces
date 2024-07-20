#include <bits/stdc++.h>
using namespace std;
constexpr int64_t inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

// @author: ZhockDen

struct dir_graph {

    int n; // 0 - based
    vector<vector<int>> adj;
    vector<vector<int>> adj_rev;
    vector<bool> vis, state;
    vector<int> topsort, label;
    bool isCycle = false;
    int st_conn_comp = 0;

    dir_graph(int n) : n(n), adj(n), adj_rev(n), vis(n, false), label(n, -1), state(n, false) {}

    void add_edge(int u, int v) { // u->v
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    void dfs(int v) {
        vis[v] = true;
        state[v] = true;
        for (int &u : adj[v]) {
            if (!vis[u])
                dfs(u);
            else if (state[u])
                isCycle = true;
        }
        state[v] = false;
        topsort.push_back(v);
    }

    bool topological_sort() {
        for (int v = 0; v < n; v++) {
            if (!vis[v]) dfs(v);
        }
        reverse(topsort.begin(), topsort.end());
        return !isCycle;
    }

    int strongly_connected_comp() {
        function<void(int, int)> dfs2 = [&](int v, int lb) -> void {
            label[v] = lb;
            for (int &u : adj_rev[v]) {
                if (label[u] == -1) dfs2(u, lb);
            }
        };
        topological_sort();
        for (int &v : topsort) {
            if (label[v] == -1) {
                dfs2(v, st_conn_comp);
                st_conn_comp++;
            }
        }
        return st_conn_comp;
    }
};

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n, m;
    cin >> n >> m;
    dir_graph gp(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gp.add_edge(x - 1, y - 1);
    }
    gp.topological_sort();
    for (auto &e : gp.topsort) cout << e+1 << " ";
    cout << "\n";
    function<int(int)> fun = [&](int i) {
        if (gp.adj_rev[i].size() == 0) return 1;
        int way = 0;
        for (auto &e : gp.adj_rev[i]) {
            way = (way + fun(e)) % mod;
        }
        return way;
    };
    cout << fun(gp.topsort[n - 1]) << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}