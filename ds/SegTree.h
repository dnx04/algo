// 0-indexed
template <typename T, typename F>
struct SegTree {
  int n, size;  // smallest size = 2^k >= n
  vector<T> seg;
  const F f;
  const T I;
  SegTree(int n, F f, const T& I) : n(n), f(f), I(I) {
    size = 1;
    while (size < n) size <<= 1;
    seg.assign(size << 1, I);
  }
  T& operator[](int k) { return seg[k + size]; }
  void set(int k, T x) { seg[k + size] = x; }  // to build
  void build() {
    for (int i = size - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[i << 1 | 1]);
  }
  void apply(int k, T x) {
    k += size, seg[k] = x;
    while (k >>= 1) seg[k] = f(seg[k << 1], seg[k << 1 | 1]);
  }
  // query [l, r)
  T query(int l, int r) {
    T L = I, R = I;
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = f(L, seg[l++]);
      if (r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }
  template <class C>
  int max_right(int l, C check) {
    assert(0 <= l && l <= n && check(I) == true);
    if (l == n) return n;
    l += size;
    T sm = I;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(f(sm, seg[l]))) {
        while (l < size) {
          l = l << 1;
          if (check(f(sm, seg[l]))) sm = f(sm, seg[l]), l++;
        }
        return l - size;
      }
      sm = f(sm, seg[l]), l++;
    } while ((l & -l) != l);
    return n;
  }
  template <typename C>
  int min_left(int r, C check) {
    assert(0 <= r && r <= n && check(I) == true);
    if (r == 0) return 0;
    r += size;
    T sm = I;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(f(seg[r], sm))) {
        while (r < size) {
          r = r << 1 | 1;
          if (check(f(seg[r], sm))) sm = f(seg[r], sm), r--;
        }
        return r + 1 - size;
      }
      sm = f(seg[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};