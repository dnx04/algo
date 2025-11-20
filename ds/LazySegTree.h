// 0-indexed
template <class T, class L, class F, class M, class C>
struct LazySegTree {
 private:
  int n, h;
  vector<T> seg;
  vector<L> laz;
  const T I;   // Identity node (e.g., 0 for sum, INF for min)
  const L L0;  // Identity laz (e.g., 0 for add, -1 for set)
  const F f;   // f: Merge 2 nodes (T, T) -> T
  const M m;   // m: Mapping laz to node (T, L) -> T
  const C c;   // c: Composition 2 laz (L prev, L next) -> next(prev)
  void apply(int p, L val) {
    seg[p] = m(seg[p], val);
    if (p < n) laz[p] = c(laz[p], val);
  }
  void pull(int p) {
    while (p > 1) {
      p >>= 1;
      seg[p] = m(f(seg[p << 1], seg[p << 1 | 1]), laz[p]);
    }
  }
  void push(int p) {
    for (int s = h; s > 0; --s) {
      int i = p >> s;
      if (laz[i] != L0) apply(i << 1, laz[i]), apply(i << 1 | 1, laz[i]), laz[i] = L0;
    }
  }

 public:
  LazySegTree(int n, T I, L L0, F f, M m, C c) : n(n), h(32 - __builtin_clz(n)), seg(n << 1 | 1, I), laz(n, L0), I(I), L0(L0), f(f), m(m), c(c) {}
  // set p to x
  void set(int p, T x) {
    p += n;
    for (int i = h; i > 0; --i) {
      int k = p >> i;
      if (laz[k] != L0) apply(k << 1, laz[k]), apply(k << 1 | 1, laz[k]), laz[k] = L0;
    }
    seg[p] = x, pull(p);
  }
  // Apply op -> [l, r)
  void apply(int l, int r, L op) {
    l += n, r += n;
    int l0 = l, r0 = r;
    push(l0), push(r0 - 1);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, op);
      if (r & 1) apply(--r, op);
    }
    pull(l0), pull(r0 - 1);
  }
  // Query [l, r)
  T query(int l, int r) {
    l += n, r += n;
    push(l), push(r - 1);
    T resL = I, resR = I;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resL = f(resL, seg[l++]);
      if (r & 1) resR = f(seg[--r], resR);
    }
    return f(resL, resR);
  }
};