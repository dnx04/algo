#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../misc/CountSubseq.h"

using Fp = modint<998244353>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  cout << CountSubseq<int, Fp>(a);
}