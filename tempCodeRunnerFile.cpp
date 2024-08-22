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

template <typename T>
struct mxsegtree {

    T zeroSum = INT32_MIN;

    T calc(T a, T b) {
        return max(a, b);
    }

    vector<T> sums;

    int size;

    void set(int i, T x, int n, int L, int R) {
        if (R == L + 1) {
            sums[n] = x;
            return;
        }
        int M = (L + R) >> 1;
        if (i < M) {
            set(i, x, 2 * n + 1, L, M);
        } else {
            set(i, x, 2 * n + 2, M, R);
        }
        sums[n] = calc(sums[2 * n + 1], sums[2 * n + 2]);
    }

    T sum(int l, int r, int n, int L, int R) {
        if (l >= R || L >= r) return zeroSum;
        if (L >= l && R <= r) return sums[n];
        int M = (L + R) >> 1;
        return calc(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
    }

    void init(vector<T> a) {
        int n = a.size();
        init(n);
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
        for (int i = 0; i < n; i++) {
            sums[size - 1 + i] = a[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            sums[i] = calc(sums[2 * i + 1], sums[2 * i + 2]);
        }
    }

    void set(int i, T x) { set(i, x, 0, 0, size); }

    T sum(int l, int r) { return sum(l, r, 0, 0, size); }
};

template <typename T>
struct mnsegtree {

    T zeroSum = INT32_MAX;

    T calc(T a, T b) {
        return min(a, b);
    }

    vector<T> sums;

    int size;

    void set(int i, T x, int n, int L, int R) {
        if (R == L + 1) {
            sums[n] = x;
            return;
        }
        int M = (L + R) >> 1;
        if (i < M) {
            set(i, x, 2 * n + 1, L, M);
        } else {
            set(i, x, 2 * n + 2, M, R);
        }
        sums[n] = calc(sums[2 * n + 1], sums[2 * n + 2]);
    }

    T sum(int l, int r, int n, int L, int R) {
        if (l >= R || L >= r) return zeroSum;
        if (L >= l && R <= r) return sums[n];
        int M = (L + R) >> 1;
        return calc(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
    }

    void init(vector<T> a) {
        int n = a.size();
        init(n);
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
        for (int i = 0; i < n; i++) {
            sums[size - 1 + i] = a[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            sums[i] = calc(sums[2 * i + 1], sums[2 * i + 2]);
        }
    }

    void set(int i, T x) { set(i, x, 0, 0, size); }

    T sum(int l, int r) { return sum(l, r, 0, 0, size); }
};

void runCase(int &testCase) {
    // cout << "#Case " << testCase << ": \n";

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    mnsegtree<int> Mn;
    mxsegtree<int> Mx;
    Mn.init(v);
    Mx.init(v);
    map<int, int> mp;
    map<int, vector<int>> mp1;
    for (int i = 0; i < n; i++) {
        mp[v[i]] = i;
        mp1[v[i]].push_back(i);
    }
    vector<int> vv;
    for (auto &[x, y] : mp) {
        vv.push_back(y);
    }
    sort(vv.begin(), vv.end());
    vector<int> res;
    int curr = 0;
    int rt = 0;
    set<int> st;
    for (int i = 0; i < mp.size(); i++) {
        // cout << i << " ";
        if (i % 2 == 0) {
            // cout << curr << "-" << vv[rt] << "mn\n";
            int E = Mx.sum(curr, vv[rt] + 1);
            // cout << E << "`";
            res.push_back(E);
            int val = INT32_MAX;
            for (auto &e : mp1[E]) {
                val = min(val, e);
                Mx.set(e, INT32_MIN);
                Mn.set(e, INT32_MAX);
            }
            st.insert(E);
            while (st.count(v[vv[rt]])) rt++;
            curr = val + 1;
        } else {
            // cout << curr << "-" << vv[rt] << "mn\n";
            int E = Mn.sum(curr, vv[rt] + 1);
            // cout << E << "`";
            res.push_back(E);
            int val = INT32_MAX;
            for (auto &e : mp1[E]) {
                val = min(val, e);
                Mx.set(e, INT32_MIN);
                Mn.set(e, INT32_MAX);
            }
            st.insert(E);
            while (st.count(v[vv[rt]])) rt++;
            curr = val + 1;
        }
    }
    cout << res.size() << "\n";
    for (auto &e : res) cout << e << " ";
    cout << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) runCase(i);

    return 0;
}