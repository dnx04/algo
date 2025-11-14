#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include "../misc/macros.h"
#include "../math/GaussBinary.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> A(n, bs(m));
  bs b(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      A[i][j] = ch - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    b[i] = ch - '0';
  }
  auto res = solve_linear(n, m, A, b);
  cout << sz(res) - 1 << '\n';
  for (auto row : res) {
    for (int j = 0; j < m; ++j) cout << row[j];
    cout << '\n';
  }
}
