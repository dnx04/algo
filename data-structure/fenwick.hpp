template <typename T>
struct fenwick_tree {
 public:
  fenwick_tree(int _n) : n(_n), fw(_n + 1) {}

  void add(int p, T x) {
    assert(0 <= p && p < n);
    ++p;
    while (p <= n) {
      fw[p - 1] += x;
      p += p & -p;
    }
  }

  // return sum of [l, r)
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return 0;
    return sum(r) - sum(l);
  }

  void reset() { fill(begin(fw), end(fw), 0); }

 private:
  int n;
  vector<T> fw;

  T sum(int r) {
    T s = 0;
    while (r > 0) {
      s += fw[r - 1];
      r -= r & -r;
    }
    return s;
  }
};