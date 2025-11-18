vector<i64> EnumerateQuotients(i64 N) {
  vector<i64> res;
  i64 f = 1;
  for (; f * f < N; f++) res.push_back(f);
  int qp1 = res.size();
  for (i64 k = 1; k * f <= N; k++) {
    res.push_back((k & 1) ? (N / k) : (res[qp1 + k / 2 - 1] / 2));
  }
  reverse(res.begin() + qp1, res.end());
  return res;
}