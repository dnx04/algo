#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/MillerRabin.h"

void solve() {
  ull x;
  cin >> x;
  cout << (isPrime(x) ? "Yes\n" : "No\n");
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
