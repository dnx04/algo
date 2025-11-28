#define pc __builtin_popcount

namespace FST {
  enum { OR, AND, XOR };
  template<class T>
  void fwht(vector<T>& a, int op, int inv) {
    int n = sz(a);
    for (int l = 1; l < n; l <<= 1)
      for (int i = 0; i < n; i += 2 * l)
        for (int j = 0; j < l; ++j) {
          T u = a[i + j], v = a[i + j + l];
          if (op == OR) a[i + j + l] += inv ? -u : u;
          else if (op == AND) a[i + j] += inv ? -v : v;
          else a[i + j] = u + v, a[i + j + l] = u - v;
        }
    if (op == XOR && inv) {
      T in = T(1) / n;
      for (auto& x : a) x *= in;
    }
  }
  template<class T>
  vector<T> conv(vector<T> a, vector<T> b, int op) {
    int n = 1; while (n < max(sz(a), sz(b))) n <<= 1;
    a.resize(n), b.resize(n);
    fwht(a, op, 0), fwht(b, op, 0);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    fwht(a, op, 1);
    return a;
  }
  template<class T>
  vector<T> subsetConv(const vector<T>& a, const vector<T>& b) {
    int n = 1, k = 0;
    while (n < max(sz(a), sz(b))) n <<= 1, k++;
    vector<vector<T>> fa(k + 1, vector<T>(n)), fb(k + 1, vector<T>(n)), h(k + 1, vector<T>(n));
    for (int i = 0; i < n; ++i) {
      if (i < sz(a)) fa[pc(i)][i] = a[i];
      if (i < sz(b)) fb[pc(i)][i] = b[i];
    }
    for (int i = 0; i <= k; ++i) fwht(fa[i], OR, 0), fwht(fb[i], OR, 0);
    for (int i = 0; i <= k; ++i)
      for (int j = 0; j <= i; ++j)
        for (int x = 0; x < n; ++x) h[i][x] += fa[j][x] * fb[i - j][x];
    for (int i = 0; i <= k; ++i) fwht(h[i], OR, 1);
    vector<T> res(n);
    for (int i = 0; i < n; ++i) res[i] = h[pc(i)][i];
    return res;
  }
}