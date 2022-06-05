#include <bits/stdc++.h>

using namespace std;

struct uf {
 public:
  uf() : _n(0) {}
  explicit uf(int n) : _n(n), p(n, -1) {}

  int merge(int a, int b) {
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }

  bool same(int a, int b) { return leader(a) == leader(b); }

  int leader(int a) {
    if (p[a] < 0) return a;
    return p[a] = leader(p[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -p[leader(a)];
  }

 private:
  int _n;
  vector<int> p;
};