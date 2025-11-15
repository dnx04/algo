vector<ll> EnumerateQuotients(ll N) {
  vector<ll> res;
  ll f = 1;
  for (; f * f < N; f++) res.push_back(f);
  int qp1 = res.size();
  for (ll k = 1; k * f <= N; k++) {
    res.push_back((k & 1) ? (N / k) : (res[qp1 + k / 2 - 1] / 2));
  }
  reverse(res.begin() + qp1, res.end());
  return res;
}