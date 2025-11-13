#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

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

#include "../graph/2SAT.h"

void solve() {
  string rid;
  cin >> rid >> rid;
  int n, m;
  cin >> n >> m;
  TwoSat ts(n);
  rep(i, 0, m) {
    int a, b, rid;
    cin >> a >> b >> rid;
    if (a < 0) a = ~(-a - 1);
    else --a;
    if (b < 0) b = ~(-b - 1);
    else --b;
    ts.either(a, b);
  }
  if (ts.solve()) {
    cout << "s SATISFIABLE\n";
    cout << "v ";
    rep(i, 0, n) { cout << (ts.values[i] ? i + 1 : -i - 1) << " "; }
    cout << "0\n";
  } else {
    cout << "s UNSATISFIABLE\n";
  }
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
