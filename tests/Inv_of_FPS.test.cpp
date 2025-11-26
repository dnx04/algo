#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../misc/macros.h"
#include "../math/Poly.h"

using namespace std;

void solve() {
  int n;
  cin >> n;
  Poly f(n);
  for (auto& i : f) cin >> i;
  auto g = f.inv(n);
  for (auto i : g) cout << i << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}