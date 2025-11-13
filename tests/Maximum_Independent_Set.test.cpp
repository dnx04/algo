#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

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
using bs = dynamic_bitset<u_int64_t>;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../misc/MaximumClique.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> eds(n, bs(n));
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    eds[u][v] = eds[v][u] = 1;
  }
  rep(i, 0, n) {
    eds[i].flip();
    eds[i][i] = 0;
  }
  Maxclique mc(eds);
  auto ans = mc.maxClique();
  cout << sz(ans) << '\n';
  for (auto i : mc.qmax) cout << i << ' ';
}
