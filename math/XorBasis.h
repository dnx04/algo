template <class T>
struct Basis {
  int B; vector<T> a; vector<i64> wt;
  Basis() : B(sizeof(T) * 8), a(B, 0), wt(B, 0) {}
  void insert(T x, i64 w = 0) {
    for (int i = B - 1; i >= 0; --i) if (x >> i & 1) {
      if (!a[i]) { a[i] = x, wt[i] = w; return; }
      if (wt[i] < w) swap(wt[i], w), swap(a[i], x);
      x ^= a[i];
    }
  }
  i64 query() {
    i64 ans = 0;
    for (auto w : wt) ans += w;
    return ans;
  }
  friend Basis intersect(const Basis& L, const Basis& R) {
    Basis res, full; int B = L.B; vector<T> mask(B, 0);
    for (T x : L.a) if (x)
      for (int j = B - 1; j >= 0; --j) if (x >> j & 1) {
        if (!full.a[j]) { full.a[j] = x; break; }
        x ^= full.a[j];
      }
    for (T x : R.a) if (x) {
      T m = x; bool k = 1;
      for (int j = B - 1; j >= 0; --j) if (x >> j & 1) {
        if (!full.a[j]) { full.a[j] = x, mask[j] = m, k = 0; break; }
        x ^= full.a[j], m ^= mask[j];
      }
      if (k) res.insert(m);
    }
    return res;
  }
};