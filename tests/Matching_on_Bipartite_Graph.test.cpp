#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../graph/HopcroftKarp.h"

void solve() {
  int l, r, m;
  cin >> l >> r >> m;
  vector<vi> g(l);
  vi btoa(r, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  cout << hopcroftKarp(g, btoa) << '\n';
  for (int i = 0; i < r; ++i) {
    if (btoa[i] != -1) {
      cout << btoa[i] << ' ' << i << '\n';
    }
  }
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
