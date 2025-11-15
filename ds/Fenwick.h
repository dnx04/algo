template <typename T>
struct Fenwick {  // 1-indexed
  int n;
  vector<T> t;
  Fenwick(int n) : n(n), t(n + 1, T(0)) {}
  void add(int p, T v) {
    while (p <= n) t[p] += v, p += (p & -p);
  }
  T sum(int p) {
    T res = 0;
    while (p) res += t[p], p -= (p & -p);
    return res;
  }
  T sum(int l, int r) {
    if (l > r) return T(0);
    return sum(r) - sum(l - 1);
  }
};