#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>

using namespace std;

#include "../fenwick.hpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick_tree<int64_t> fw(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    fw.add(i, x);
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t)
      cout << fw.sum(l, r) << '\n';
    else
      fw.add(l, r);
  }
}