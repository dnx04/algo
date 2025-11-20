struct DSURollback {
  int n;
  vector<int> p;
  vector<pair<int*, int>> his;
  DSURollback(int n) : n(n), p(n, -1) {}
  int root(int s) {
    while (p[s] >= 0) s = p[s];
    return s;
  }
  void merge(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (p[a] < p[b]) swap(a, b);
    his.eb(&p[a], p[a]), his.eb(&p[b], p[b]), his.eb(&n, n);
    n--, p[b] += p[a], p[a] = b;
  }
  void undo(int cnt) {
    while (cnt--) {
      auto [a, b] = his.back();
      his.pop_back();
      *a = b;
    }
  }
};
