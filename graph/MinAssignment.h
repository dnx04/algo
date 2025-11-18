pair<i64, vector<int>> MinAssignment(const vector<vector<i64>>& W) {
  int n = W.size(), m = W[0].size();  // assert(n <= m);
  vector<i64> v(m), dist(m);           // v: potential
  vector<int> L(n, -1), R(m, -1);     // matching pairs
  vector<int> idx(m), prev(m);
  iota(idx.begin(), idx.end(), 0);

  i64 w, h;
  int j, l, s, t;
  auto reduce = [&]() {
    if (s == t) {
      l = s;
      w = dist[idx[t++]];
      for (int k = t; k < m; ++k) {
        j = idx[k];
        h = dist[j];
        if (h > w) continue;
        if (h < w) t = s, w = h;
        idx[k] = idx[t];
        idx[t++] = j;
      }
      for (int k = s; k < t; ++k) {
        j = idx[k];
        if (R[j] < 0) return 1;
      }
    }
    int q = idx[s++], p = R[q];
    for (int k = t; k < m; ++k) {
      j = idx[k];
      h = W[p][j] - W[p][q] + v[q] - v[j] + w;
      if (h < dist[j]) {
        dist[j] = h;
        prev[j] = p;
        if (h == w) {
          if (R[j] < 0) return 1;
          idx[k] = idx[t];
          idx[t++] = j;
        }
      }
    }
    return 0;
  };
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) dist[k] = W[i][k] - v[k], prev[k] = i;
    s = t = 0;
    while (!reduce());
    for (int k = 0; k < l; ++k) v[idx[k]] += dist[idx[k]] - w;
    for (int k = -1; k != i;) R[j] = k = prev[j], swap(j, L[k]);
  }
  i64 ret = 0;
  for (int i = 0; i < n; ++i) ret += W[i][L[i]];  // (i, L[i]) is a solution
  return {ret, L};
}