#include <bits/stdc++.h>

using namespace std;

struct uf {
 public:
  uf(int _n) : n(_n), p(_n, -1) {}

  int merge(int a, int b) {
    int x = head(a), y = head(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }

  bool same(int a, int b) { return head(a) == head(b); }

  int head(int a) {
    if (p[a] < 0) return a;
    return p[a] = head(p[a]);
  }

  int size(int a) {
    assert(0 <= a && a < n);
    return -p[head(a)];
  }

 private:
  int n;
  vector<int> p;
};

signed main() {
  int n, q;
  cin >> n >> q;
  uf dsu(n);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t)
      cout << dsu.same(x, y) << '\n';
    else
      dsu.merge(x, y);
  }
}