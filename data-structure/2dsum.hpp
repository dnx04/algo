// matrix should be 1-indexed
auto init = [&](vector<vector<int>> &a, int r, int c) {
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
};
auto sum = [&](const vector<vector<int>> &a, int r1, int c1, int r2, int c2) {
  return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
};