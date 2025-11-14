using vec = array<Fp, 3>;
using matrix = array<vec, 3>;
const matrix id = matrix({vec{1, 0, 0}, vec{0, 1, 0}, vec{0, 0, 1}});

matrix operator*(const matrix& a, const matrix& b) {
  matrix res;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

matrix operator^(matrix a, ll k) {
  matrix res = id;
  while (k) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}

vec operator*(const matrix& a, const vec& b) {
  vec c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      c[i] += a[i][j] * b[j];
    }
  }
  return c;
}