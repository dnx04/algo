#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../math/Matrix.h"
#include "../math/ModInt.h"

using Fp = modint<998244353>;

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  Matrix<Fp> A(n);
  rep(i, 0, n) rep(j, 0, n) cin >> A.d[i][j];
  A = A ^ k;
  rep(i, 0, n) { rep(j, 0, n) cout << A.d[i][j] << " \n"[j == n - 1]; }
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
