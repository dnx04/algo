#define PROBLEM "https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces"

#include "../misc/macros.h"
#include "../math/XorBasis.h"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<vector<ll>> basis(2);
    for (int i : {0, 1}) {
      int s;
      cin >> s;
      basis[i].resize(s);
      for (auto& x : basis[i]) cin >> x;
    }
    auto xi = XorInter(basis[0], basis[1]);
    cout << sz(xi) << ' ';
    for (auto v : xi) cout << v << ' ';
    cout << '\n';
  }
}