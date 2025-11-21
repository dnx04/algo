#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../misc/macros.h"
#include "../misc/Compressor.h"
#include "../ds/SegTree.h"

void solve() {
  int n;
  cin >> n;
  vi a(n), tr(n, -1);
  for (auto& x : a) cin >> x;
  a = compressor(a);
  SegTree st(n, [&](pii a, pii b) { return max(a, b); }, pii{0, -1});
  st.apply(a[0], {1, 0});
  for (int i = 1; i < n; ++i) {
    auto [lis, idx] = st.query(0, a[i]);
    if (idx == -1)
      tr[i] = i;
    else
      tr[i] = idx;
    st.apply(a[i], {lis + 1, i});
  }
  auto [lis, u] = st.query(0, n);
  cout << lis << '\n';
  vi pos;
  while (true) {
    pos.eb(u);
    if (tr[u] == -1 || tr[u] == u) break;
    u = tr[u];
  }
  reverse(all(pos));
  for (auto u : pos) cout << u << ' ';
}

int main() {
  solve();
}