#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../math/DivModSum.h"

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << divsum(b, a, m, n) << '\n';
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
