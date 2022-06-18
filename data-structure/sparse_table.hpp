template <typename T>
struct sparse_table {
  int n, k;
  vector<vector<T>> st;
  T f(T x = 1e9, T y = 1e9) { return min(x, y); }
  sparse_table(const vector<T> &v)
      : n(v.size()), k(__lg(n) + 1), st(n, vector<T>(k)) {
    for (int i = 0; i < n; ++i) st[i][0] = f(v[i]);
    for (int j = 1; j < k; j++)
      for (int i = 0; i + (1 << j) <= n; ++i)
        st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  };
  T query(int l, int r) {
    T sum = 1e9;
    for (int j = k - 1; j >= 0; --j) {
      if ((1 << j) <= r - l + 1) {
        sum = f(sum, st[l][j]);
        l += 1 << j;
      }
    }
    return sum;
  }
};