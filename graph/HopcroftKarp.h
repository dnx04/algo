struct HopcroftKarp {
  vector<vi> g; vi btoa, A, B;
  HopcroftKarp(int L, int R) : g(L), btoa(R, -1), A(L), B(R) {}
  void add(int u, int v) { g[u].pb(v); }
  bool dfs(int a, int L) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || dfs(btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  }
  int solve() {
    int res = 0; vi cur, next;
    for (;;) {
      fill(all(A), 0), fill(all(B), 0), cur.clear();
      for (int a : btoa) if (a != -1) A[a] = -1;
      for (int a = 0; a < sz(g); ++a) if (!A[a]) cur.pb(a);
      for (int lay = 1;; lay++) {
        bool islast = 0; next.clear();
        for (int a : cur) for (int b : g[a]) {
          if (btoa[b] == -1) B[b] = lay, islast = 1;
          else if (btoa[b] != a && !B[b]) B[b] = lay, next.pb(btoa[b]);
        }
        if (islast) break;
        if (next.empty()) return res;
        for (int a : next) A[a] = lay;
        cur.swap(next);
      }
      for (int a = 0; a < sz(g); ++a) res += dfs(a, 0);
    }
  }
};