#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../graph/MinAssignment.h"

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> W(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> W[i][j];
    }
  }
  auto [ret, L] = MinAssignment(W);
  cout << ret << '\n';
  rep(i, 0, n) cout << L[i] << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
