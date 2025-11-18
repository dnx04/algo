template <typename T, typename L>
struct LazySegTree {
  int n, h;
  vector<T> seg;
  vector<L> lazy;
  const T I;   // Identity node (e.g., 0 for sum, INF for min)
  const L L0;  // Identity lazy (e.g., 0 for add, -1 for set)
  // f: Merge 2 nodes (T, T) -> T
  // m: Mapping lazy to node (T, L) -> T
  // c: Composition 2 lazy (L, L) -> L
  function<T(T, T)> f;
  function<T(T, L)> m;
  function<L(L, L)> c;
  LazySegTree(int n, T I, L L0, auto f, auto m, auto c) : n(n), h(32 - __builtin_clz(n)), seg(2 * n, I), lazy(n, L0), I(I), L0(L0), f(f), m(m), c(c) {}
  void apply(int p, L val) {
    seg[p] = m(seg[p], val);
    if (p < n) lazy[p] = c(lazy[p], val);
  }
  void pull(int p) {
    while (p > 1) {
      p >>= 1;
      seg[p] = m(f(seg[2 * p], seg[2 * p + 1]), lazy[p]);
    }
  }
  void push(int p) {
    for (int s = h; s > 0; --s) {
      int i = p >> s;
      if (lazy[i] != L0) {
        apply(2 * i, lazy[i]);
        apply(2 * i + 1, lazy[i]);
        lazy[i] = L0;
      }
    }
  }
  void set(int p, T x) {
    p += n;
    for (int i = h; i > 0; --i) {  // Cần push sạch đường đi trước khi set
      int node = p >> i;
      if (lazy[node] != L0) {
        apply(2 * node, lazy[node]);
        apply(2 * node + 1, lazy[node]);
        lazy[node] = L0;
      }
    }
    seg[p] = x, pull(p);  // Cập nhật ngược lên
  }
  // Update đoạn [l, r)
  void upd(int l, int r, L val) {
    l += n, r += n;
    int l0 = l, r0 = r;
    push(l0), push(r0 - 1);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, val);
      if (r & 1) apply(--r, val);
    }
    pull(l0), pull(r0 - 1);
  }
  // Query đoạn [l, r)
  T qry(int l, int r) {
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