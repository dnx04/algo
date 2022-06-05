#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>

using namespace std;

#include "algo/data-structure/union_find.hpp"

signed main() {
  int n, q;
  cin >> n >> q;
  uf dsu(n);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t)
      cout << dsu.same(x, y) << '\n';
    else
      dsu.merge(x, y);
  }
}