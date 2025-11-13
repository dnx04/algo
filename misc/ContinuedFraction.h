typedef double d;  // for N ~ 1e7; long double for N ~ 1e9
pair<ll, ll> approximate(d x, ll N) {
  ll LP = 0, LQ = 1, P = 1, Q = 0, inf = LLONG_MAX;
  d y = x;
  for (;;) {
    ll lim = min(P ? (N - LP) / P : inf, Q ? (N - LQ) / Q : inf),
       a = (ll) floor(y), b = min(a, lim), NP = b * P + LP, NQ = b * Q + LQ;
    if (a > b) {
      // If b > a/2, we have a semi-convergent that gives us a
      // better approximation; if b = a/2, we *may* have one.
      // Return {P, Q} here for a more canonical approximation.
      return (abs(x - (d) NP / (d) NQ) < abs(x - (d) P / (d) Q)) ? make_pair(NP, NQ) : make_pair(P, Q);
    }
    if (abs(y = 1 / (y - (d) a)) > 3 * N) return {NP, NQ};
    LP = P;
    P = NP;
    LQ = Q;
    Q = NQ;
  }
}