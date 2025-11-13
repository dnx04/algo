using ll = long long;
struct Frac {
  ll p, q;
};

template <class Func>
Frac FracLowerBound(Func f, ll maxq, ll maxp) {
  Frac lo{0, 1}, hi{1, 1}, mid;  // Set hi to 1/0 for (0, inf)
  if (f(lo)) return lo;
  assert(f(hi));
  for (int it = 0, dir = 1; it < 3 || !dir; ++it) {
    // invariant: f(lo) == !dir, f(hi) == dir
    for (ll step = 1, adv = 1, now = 0;; adv ? step *= 2 : step /= 2) {
      now += step;
      mid = {lo.p * now + hi.p, lo.q * now + hi.q};
      if (abs(mid.p) > maxp || mid.q > maxq || f(mid) != dir) now -= step, adv = 0;
      if (!step) break;
    }
    if (mid.p != hi.p) it = 0;
    hi = lo;
    lo = mid;
    dir = !dir;
  }
  // (lo, hi) are consecutive with f(lo) == 0, f(hi) == 1
  return hi;
}