#include "ModInt.h"
#include "MillerRabin.h"

u64 pollard(u64 n) {
  u64 x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  auto f = [&](u64 x) { return modmul(x, x, n) + i; };
  while (t++ % 40 || gcd(prd, n) == 1) {
    if (x == y) x = ++i, y = f(x);
    if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
    x = f(x), y = f(f(y));
  }
  return gcd(prd, n);
}
vector<u64> factor(u64 n) {
  if (n == 1) return {};
  if (isPrime(n)) return {n};
  u64 x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), all(r));
  return l;
}