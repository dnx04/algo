template <typename T, typename F>
struct SegTree {  // 1-indexed
  int n;
  vector<T> seg;
  const F f;
  const T I;
  SegTree(int n, F f, const T& I) : n(n), seg(2 * n + 1), f(f), I(I) {}
  void set(int k, T x) { seg[k + n] = x; }
  void upd(int k, T x) {
    k += n, seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[k << 1], seg[k << 1 | 1]);
    }
  }
  // query [l, r)
  T qry(int l, int r) {
    T L = I, R = I;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = f(L, seg[l++]);
      if (r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }
  T& operator[](const int& k) { return seg[k + n]; }
};