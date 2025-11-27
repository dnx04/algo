template <class T>
struct Matrix {
  int r, c;
  vector<vector<T>> a;
  Matrix(int n) : Matrix(n, n) {}
  Matrix(int r, int c) : r(r), c(c), a(r, vector<T>(c, T(0))) {}
  Matrix(const vector<vector<T>>& v) : r(sz(v)), c(v.empty() ? 0 : sz(v[0])), a(v) {}
  vector<T>& operator[](int i) { return a[i]; }
  const vector<T>& operator[](int i) const { return a[i]; }
  static Matrix eye(int n) {
    Matrix res(n);
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    return res;
  }
  Matrix operator*(const Matrix& b) const {
    Matrix res(r, b.c);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
        if (a[i][k] != T(0))
          for (int j = 0; j < b.c; ++j) res[i][j] += a[i][k] * b[k][j];
    return res;
  }
  Matrix pow(u64 k) const {
    Matrix res = eye(r), b = *this;
    while (k) {
      if (k & 1) res = res * b;
      b = b * b, k >>= 1;
    }
    return res;
  }
  // destructive
  pair<T, int> gauss() {
    int rank = 0;
    T det = 1;
    for (int j = 0; j < c && rank < r; ++j) {
      int k = rank;
      while (k < r && a[k][j] == T(0)) k++;
      if (k == r) {
        det = 0;
        continue;
      }
      swap(a[rank], a[k]);
      if (rank != k) det = -det;
      det *= a[rank][j];
      T inv = T(1) / a[rank][j];
      for (int l = j; l < c; ++l) a[rank][l] *= inv;
      for (int i = 0; i < r; ++i)
        if (i != rank && a[i][j] != T(0)) {
          T fac = a[i][j];
          for (int l = j; l < c; ++l) a[i][l] -= a[rank][l] * fac;
        }
      rank++;
    }
    return {det, rank};
  }
  pair<vector<T>, vector<vector<T>>> solve(const Matrix& b) const {
    if (r != b.r || b.c != 1) return {{}, {}};
    Matrix mat(r, c + 1);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) mat[i][j] = a[i][j];
      mat[i][c] = b[i][0];
    }
    int rank = mat.gauss().second;
    vector<T> sol(c, T(0));
    vector<int> piv;
    vector<bool> is_free(c, 1);
    for (int i = 0; i < rank; ++i) {
      int j = 0;
      while (j <= c && mat[i][j] == T(0)) j++;
      if (j == c) return {{}, {}};
      piv.push_back(j);
      is_free[j] = 0;
      sol[j] = mat[i][c];
    }
    for (int i = rank; i < r; ++i)
      if (mat[i][c] != T(0)) return {{}, {}};
    vector<vector<T>> ker;
    for (int j = 0; j < c; ++j) {
      if (is_free[j]) {
        vector<T> v(c, T(0));
        v[j] = T(1);
        for (int i = 0; i < sz(piv); ++i) v[piv[i]] = T(0) - mat[i][j];
        ker.push_back(v);
      }
    }
    return {sol, ker};
  }
  T det() const {
    if (r != c) return T(0);
    Matrix tmp = *this;
    auto [d, rank] = tmp.gauss();
    return (rank == r) ? d : T(0);
  }
  int rank() const {
    Matrix tmp = *this;
    return tmp.gauss().second;
  }
  Matrix inv() const {
    if (r != c) return Matrix(0, 0);
    Matrix tmp(r, 2 * c);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) tmp[i][j] = a[i][j];
      tmp[i][i + c] = 1;
    }
    auto [d, rank] = tmp.gauss();
    if (rank != r) return Matrix(0, 0);
    Matrix res(r, c);
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) res[i][j] = tmp[i][j + c];
    return res;
  }
};