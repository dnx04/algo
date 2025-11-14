#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../misc/macros.h"
#include "../graph/MinAssignment.h"

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> W(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> W[i][j];
    }
  }
  auto [ret, L] = MinAssignment(W);
  cout << ret << '\n';
  for (int i = 0; i < n; ++i) cout << L[i] << ' ';
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
