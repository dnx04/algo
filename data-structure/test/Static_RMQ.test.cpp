#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "bits/extc++.h"

using namespace std;

#include "../sparse_table.hpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sparse_table<int> st(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r - 1) << '\n';
  }
}