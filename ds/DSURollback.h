struct DSURollback {
  // Stores the number of disjoint trees.
  int n;
  // If p[i] < 0, i is a root node with a tree size of -p[i].
  // Otherwise, p[i] represents the parent of i.
  vector<int> p;
  vector<pair<int *, int>> changes;
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
    changes.emplace_back(&p[a], p[a]);
    changes.emplace_back(&p[b], p[b]);
    changes.emplace_back(&n, n);
    n--;
    p[b] += p[a];
    p[a] = b;
  }
  void undo(int cnt) {
    while (cnt--) {
      auto [a, b] = changes.back();
      changes.pop_back();
      *a = b;
    }
  }
};
