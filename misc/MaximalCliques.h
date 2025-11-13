// Usage: cliques(g, [&](const bs &clique) { callback }, ~bs(n), bs(n), bs(n));

template <class F>
void cliques(vector<bs>& eds, F f, bs P, bs X, bs R) {
  f(R);
  if (!P.any() && !X.any()) return;
  // if only need to find all maximal cliques
  // auto q = (P | X).find_first();
  // auto cands = P & ~eds[q];
  for (int i = 0; i < sz(eds); ++i) {
    if (P[i]) {
      R[i] = 1;
      cliques(eds, f, P & eds[i], X & eds[i], R);
      R[i] = P[i] = 0, X[i] = 1;
    }
  }
}