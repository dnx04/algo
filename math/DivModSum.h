ll sumsq(ll to) { return to / 2 * ((to - 1) | 1); }

// sum( (a + d*i) / m ) for i in [0, n-1]
ll divsum(ll a, ll d, ll m, ll n) {
  ll res = d / m * sumsq(n) + a / m * n;
  d %= m, a %= m;
  if (!d) return res;
  ll to = (n * d + a) / m;
  return res + (n - 1) * to - divsum(m - 1 - a, m, d, to);
}
// sum( (a + d*i) % m ) for i in [0, n-1]
ll modsum(ll a, ll d, ll m, ll n) {
  a = ((a % m) + m) % m, d = ((d % m) + m) % m;
  return n * a + d * sumsq(n) - m * divsum(a, d, m, n);
}