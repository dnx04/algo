template <class T>
struct Matrix {
  using vec = vector<T>;
  int n;
  vector<vec> a;
  Matrix(int n = 0) : n(n), a(n, vec(n, 0)) {}
  Matrix(const vector<vec>& a) : n(sz(a)), a(a) {}
  vec& operator[](int i) { return a[i]; }
  const vec& operator[](int i) const { return a[i]; }
  Matrix operator*(const Matrix& b) const {
    Matrix res(n);
    for (int i = 0; i < n; ++i)
      for (int k = 0; k < n; ++k)
        for (int j = 0; j < n; ++j)
          res[i][j] += a[i][k] * b[k][j];
    return res;
  }
  Matrix operator^(u64 k) const {
    Matrix res(n), b = *this;
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (k) {
      if (k & 1) res = res * b;
      b = b * b, k >>= 1;
    }
    return res;
  }
  vec operator*(const vec& v) const {  // b(v)
    vec c(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) c[i] += a[i][j] * v[j];
    return c;
  }
};