#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#include "../math/ModInt.h"
using Fp = modint<998244353>;

#include "../math/FST.h"

void solve() {
  int n;
  cin >> n;
  vector<Fp> a(1 << n), b(1 << n);
  rep(i, 0, 1 << n) cin >> a[i];
  rep(i, 0, 1 << n) cin >> b[i];
  auto c = conv(a, b, "xor");
  rep(i, 0, 1 << n) cout << c[i] << " \n"[i == (1 << n) - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
//   cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
