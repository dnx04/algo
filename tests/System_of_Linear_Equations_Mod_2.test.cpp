#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

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

#include "../math/GaussBinary.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> A(n, bs(m));
  bs b(n);
  rep(i, 0, n) {
    rep(j, 0, m) {
      char ch;
      cin >> ch;
      A[i][j] = ch - '0';
    }
  }
  rep(i, 0, n) {
    char ch;
    cin >> ch;
    b[i] = ch - '0';
  }
  auto res = solve_linear(n, m, A, b);
  cout << sz(res) - 1 << '\n';
  for(auto row: res) {
    rep(j, 0, m) cout << row[j];
    cout << '\n';
  }
}
