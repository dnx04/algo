#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#define IGNORE

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../math/ModLog.h"

void solve() {
  ll a, b, m;
  cin >> a >> b >> m;
  if (a == 0) {
    if (b == 0)
      cout << 1 << '\n';
    else
      cout << -1 << '\n';
    return;
  }
  if(b == 1) {
    cout << 0 << '\n';
    return;
  }
  cout << modLog(a, b, m) << '\n';
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
