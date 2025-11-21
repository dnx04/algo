#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../misc/macros.h"
#include "../math/Factor.h"

void solve() {
  u64 p;
  cin >> p;
  if (p == 2) {
    cout << "1\n";
    return;
  }
  auto f = factor(p - 1);
  sort(all(f));
  f.erase(unique(all(f)), f.end());
  for (int g = 2;; ++g) {
    bool ok = true;
    for (auto pf : f) {
      if (modpow(g, (p - 1) / pf, p) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << g << '\n';
      break;
    }
  }
}

int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}