// Tính sum_{x=0}^{n-1} floor((a*x + b) / m)
u64 divsum(u64 n, u64 m, i64 a, i64 b) {
  u64 ans = 0;
  if (a < 0) {
    i64 a2 = (a % (i64) m + m) % m;
    ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m), a = a2;
  }
  if (b < 0) {
    i64 b2 = (b % (i64) m + m) % m;
    ans -= 1ULL * n * ((b2 - b) / m), b = b2;
  }
  u64 ua = a, ub = b;
  while (true) {
    if (ua >= m) ans += (n - 1) * n / 2 * (ua / m), ua %= m;
    if (ub >= m) ans += n * (ub / m), ub %= m;
    u64 y_max = ua * n + ub;
    if (y_max < m) break;
    n = y_max / m, ub = y_max % m, swap(m, ua);
  }
  return ans;
}

// Tính sum_{x=0}^{n-1} ((a*x + b) % m)
u64 modsum(u64 n, u64 m, i64 a, i64 b) {
  i128 sum = (i128) a * n * (n - 1) / 2 + (i128) b * n;
  return (u64) (sum - (i128) m * divsum(n, m, a, b));
}

// Tính min_{x=0}^{n-1} ((a*x + b) % m)
i64 minmod(u64 n, u64 m, i64 a, i64 b) {
  i64 lo = 0, hi = m - 1, ans = b;
  while (lo <= hi) {
    auto mid = (lo + hi) / 2;
    auto cnt = divsum(n, m, a, b) - divsum(n, m, a, b - mid - 1);
    if (cnt > 0) ans = mid, hi = mid - 1;
    else lo = mid + 1;
  }
  return ans;
}