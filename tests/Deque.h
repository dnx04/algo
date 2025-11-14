#define PROBLEM "https://judge.yosupo.jp/problem/deque"

#include "../misc/macros.h"

void solve() {
  int q;
  cin >> q;
  deque<int> dq;
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int x;
      cin >> x;
      dq.push_front(x);
    } else if (t == 1) {
      int x;
      cin >> x;
      dq.push_back(x);
    } else if (t == 2) {
      dq.pop_front();
    } else if (t == 3) {
      dq.pop_back();
    } else if (t == 4) {
      int i;
      cin >> i;
      cout << dq[i] << '\n';
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}