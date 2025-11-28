using bs = tr2::dynamic_bitset<uint64_t>;

// Usage: bs P(n), X(n), R(n); P.set(); EnumClique(g, [&](bs& c){...}, P, X, R);
template <class F>
void EnumClique(vector<bs>& g, F f, bs P, bs X, bs R) {
  f(R); 
  if (P.none() && X.none()) return;
  // if only need to find all maximal cliques
  // auto q = (P | X).find_first();
  // auto cands = P & ~g[q]; // then trav through cands
  for (auto i = P.find_first(); i < sz(P); i = P.find_next(i)) {
    R[i] = 1;
    EnumClique(g, f, P & g[i], X & g[i], R);
    R[i] = 0, P[i] = 0, X[i] = 1;
  }
}

// Usage: bs P(n), R(n), sol; u64 ans=0; P.set(); MaxClique(g, P, R, sol, ans);
void MaxClique(vector<bs>& g, bs P, bs R, bs& sol, u32& res) {
  if (R.count() + P.count() <= res) return;
  if (P.none()) { res = R.count(), sol = R; return; }
  auto q = P.find_first(), max_k = u64(0);
  for (auto i = q; i < sz(P); i = P.find_next(i)) {
    auto k = (P & g[i]).count();
    if (k > max_k) max_k = k, q = i;
  }
  bs cands = P & ~g[q];
  for (auto i = cands.find_first(); i < sz(cands); i = cands.find_next(i)) {
    R[i] = 1, MaxClique(g, P & g[i], R, sol, res);
    R[i] = P[i] = 0;
  }
}