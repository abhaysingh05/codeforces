/**
 *    author:  tourist
 *    created: 30.08.2024 07:31:34
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    string s;
    cin >> s;
    vector<int> cnt(3);
    int skip = 0;
    for (int i = 1; i < n; i++) {
      if (g[i].size() == 1) {
        int d = (s[i] == '?' ? 2 : int(s[i] - '0'));
        cnt[d] += 1;
      } else {
        if (s[i] == '?') {
          skip += 1;
        }
      }
    }
    int root = (s[0] == '?' ? 2 : int(s[0] - '0'));
    int it = 0;
    while (root == 2 || cnt[2] > 0) {
      if (it == 0) {
        if (root == 2) {
          if (cnt[0] == cnt[1] && skip % 2 == 1) {
            skip = 0;
          } else {
            root = (cnt[0] > cnt[1] ? 1 : 0);
          }
        } else {
          cnt[2] -= 1;
          cnt[root ^ 1] += 1;
        }
      } else {
        if (root == 2) {
          root = (cnt[0] > cnt[1] ? 0 : 1);
        } else {
          cnt[2] -= 1;
          cnt[root] += 1;
        }
      }
      it ^= 1;
    }
    cout << cnt[root ^ 1] << '\n';
  }
  return 0;
}
