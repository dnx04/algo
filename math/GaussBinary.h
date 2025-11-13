vector<bs> solve_linear(int n, int m, vector<bs> A, bs b) {
  int rk = 0;
  rep(j, 0, m) {
    if (rk == n) break;
    rep(i, rk + 1, n) if (A[i][j]) {
      swap(A[rk], A[i]);
      if (b[rk] != b[i]) b[rk] = !b[rk], b[i] = !b[i];
      break;
    }
    if (!A[rk][j]) continue;
    rep(i, 0, n) if (i != rk) {
      if (A[i][j]) {
        b[i] = b[i] ^ b[rk], A[i] = A[i] ^ A[rk];
      }
    }
    ++rk;
  }
  rep(i, rk, n) if (b[i]) return {};
  vector<bs> res(1, bs(m));

  vi pivot(m, -1);
  int p = 0;
  rep(i, 0, rk) {
    while (!A[i][p]) ++p;
    res[0][p] = b[i], pivot[p] = i;
  }
  rep(j, 0, m) if (pivot[j] == -1) {
    bs x(m);
    x[j] = 1;
    rep(k, 0, j) if (pivot[k] != -1 && A[pivot[k]][j]) x[k] = 1;
    res.eb(x);
  }
  return res;
}
