#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../misc/macros.h"
#include "../strings/Z.h"

void solve() {
  string s;
  cin >> s;
  auto z = Z(s);
  cout << len(s) << ' ';
  for (int i = 1; i < len(z); ++i) cout << z[i] << ' ';
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
