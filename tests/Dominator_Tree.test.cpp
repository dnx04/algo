#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#include "../graph/Dominator.h"

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<vi> g(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  auto tree = DomTree(g, s);
  tree[s] = s;
  rep(i, 0, n) cout << tree[i] << ' ';
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
