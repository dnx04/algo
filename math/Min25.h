template <class T>
struct Min25 {
  i64 n;
  int sq;
  vector<int> primes, id1, id2;
  vector<i64> vals;
  vector<T> g0, g1;  // g0: sum p^0, g1: sum p^1
  int id(i64 x) { return x <= sq ? id1[x] : id2[n / x]; }
  void init(i64 N) {
    n = N, sq = sqrt(n);
    primes.clear();
    vector<bool> is_p(sq + 1, true);
    for (int i = 2; i <= sq; ++i) {
      if (is_p[i]) {
        primes.pb(i);
        for (int j = i * 2; j <= sq; j += i) is_p[j] = false;
      }
    }
    vals.clear(), id1.assign(sq + 1, 0), id2.assign(sq + 1, 0);
    for (i64 l = 1, r; l <= n; l = r + 1) {
      i64 v = n / l;
      r = n / v;
      vals.pb(v);
      if (v <= sq) id1[v] = sz(vals) - 1;
      else id2[n / v] = sz(vals) - 1;
    }
    g0.resize(sz(vals)), g1.resize(sz(vals));
    T inv2 = T(1) / T(2);
    for (int i = 0; i < sz(vals); ++i) {
      T v = T(vals[i]);
      g0[i] = v - 1;
      g1[i] = v * (v + 1) * inv2 - 1;
    }
    for (int p : primes) {
      T sp0 = g0[id(p - 1)], sp1 = g1[id(p - 1)];
      i64 p2 = (i64) p * p;
      T tp = T(p);
      for (int i = 0; i < sz(vals); ++i) {
        if (vals[i] < p2) break;
        int k = id(vals[i] / p);
        g0[i] -= g0[k] - sp0;
        g1[i] -= tp * (g1[k] - sp1);
      }
    }
  }
  // A, B: f(p) = A*1 + B*p
  // func: (p, e) -> f(p^e) trả về T
  template <class Func>
  T solve(T A, T B, Func f_pe) {
    vector<T> s_fp(sz(primes) + 1);
    for (int i = 0; i < sz(primes); ++i)
      s_fp[i + 1] = s_fp[i] + A + B * T(primes[i]);

    auto S = [&](auto&& self, i64 x, int j) -> T {
      if (x <= 1 || (j < sz(primes) && primes[j] > x)) return 0;
      int k = id(x);
      T ans = A * g0[k] + B * g1[k];
      ans -= s_fp[j];
      for (int i = j; i < sz(primes); ++i) {
        i64 p = primes[i];
        if (p * p > x) break;
        i64 pe = p;
        for (int e = 1; pe * p <= x; ++e) {
          ans += f_pe(p, e) * self(self, x / pe, i + 1);
          ans += f_pe(p, e + 1);
          pe *= p;
        }
      }
      return ans;
    };
    return S(S, n, 0) + 1;
  }
};