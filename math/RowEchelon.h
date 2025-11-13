using ld = double;
using mat = vector<vector<ld>>;
const ld EPS = 1e-9;

pair<vector<int>, int> RowEchelon(mat& A) {
  int n = A.size(), m = A[0].size(), sgn = 1;
  vector<int> piv;
  for (int i = 0, rnk = 0; i < m && rnk < n; ++i) {
    for (int j = rnk + 1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[rnk][i])) swap(A[j], A[rnk]), sgn = -sgn;
    if (abs(A[rnk][i]) < EPS) continue;
    for (int j = 0; j < n; ++j) {
      ld coef = A[j][i] / A[rnk][i];
      if (j == rnk || abs(coef) < EPS) continue;
      for (int k = 0; k < m; ++k) A[j][k] -= coef * A[rnk][k];
    }
    piv.push_back(i);
    ++rnk;
  }
  return {piv, sgn};
}

vector<ld> SolveLinear(mat A, vector<ld> b) {
  int n = A.size(), m = A[0].size();
  for (int i = 0; i < n; i++) A[i].push_back(b[i]);
  auto [piv, _] = RowEchelon(A);
  int r = piv.size();
  for (int i = r; i < n; i++)
    if (abs(A[i][m]) > EPS) return {};  // vô nghiệm
  vector<ld> x(m, 0);
  for (int i = r - 1; i >= 0; --i) {
    int c = piv[i];
    ld val = A[i][m];
    for (int j = c + 1; j < m; j++) val -= A[i][j] * x[j];
    x[c] = abs(A[i][c]) < EPS ? 0 : val / A[i][c];
  }
  return x;  // nếu rank < m => nghiệm bất kỳ với biến tự do = 0
}
