#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../geometry/ClosestPair.h"

void solve() {
    int n;
    cin >> n;
    vector<Point<ll>> p(n);
    rep(i, 0, n) cin >> p[i].x >> p[i].y;
    auto ans = closest(p);
    int p1, p2;
    rep(i, 0, n) {
        if (p[i] == ans.first) {
            p1 = i;
            break;
        }
    }
    rep(i, 0, n) {
        if (i != p1 && p[i] == ans.second) {
            p2 = i;
            break;
        }
    }
    cout << p1 << ' ' << p2 << '\n';
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
