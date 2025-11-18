i64 sumsq(i64 to) { return to / 2 * ((to - 1) | 1); }

// sum( (a + d*i) / m ) for i in [0, n-1]
i64 divsum(i64 a, i64 d, i64 m, i64 n) {
  i64 res = d / m * sumsq(n) + a / m * n;
  d %= m, a %= m;
  if (!d) return res;
  i64 to = (n * d + a) / m;
  return res + (n - 1) * to - divsum(m - 1 - a, m, d, to);
}
// sum( (a + d*i) % m ) for i in [0, n-1]
i64 modsum(i64 a, i64 d, i64 m, i64 n) {
  a = ((a % m) + m) % m, d = ((d % m) + m) % m;
  return n * a + d * sumsq(n) - m * divsum(a, d, m, n);
}