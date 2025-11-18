#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../misc/macros.h"
#include "../ds/RMQ.h"

void solve() {
  int n, q;
  cin >> n >> q;
  vector<i32> a(n);
  for (auto& x : a) cin >> x;
  RMQ rmq(a, [&](const i32& x, const i32& y) { return min(x, y); });
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l, r) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
