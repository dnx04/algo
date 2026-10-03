#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/Factor.h"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    i64 n;
    cin >> n;
    auto f = factor(n);
    cout << len(f) << ' ';
    sort(all(f));
    for (auto fac : f) cout << fac << ' ';
    cout << '\n';
  }
}
