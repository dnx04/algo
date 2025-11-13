#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include <bits/extc++.h>

#include <tr2/dynamic_bitset>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace tr2;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};
using fast_map = gp_hash_table<int, int, chash>;
using bs = dynamic_bitset<u_int64_t>;  // lmao

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../math/ModInt.h"
#include "../misc/MaximalCliques.h"

using Fp = modint<998244353>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Fp> x(n);
  rep(i, 0, n) cin >> x[i];
  vector<bs> g(n, bs(n));
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
  Fp ans = 0;
  cliques(g, [&](const bs &clique) {
    if(!clique.any()) return;
    Fp prod = 1;
    for(int i = clique.find_first(); i < n; i = clique.find_next(i)) prod *= x[i];
    ans += prod;
  }, ~bs(n), bs(n), bs(n));
  cout << ans << '\n';
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
