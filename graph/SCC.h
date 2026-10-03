template <class G>
struct SCC {
 public:
  vector<vi> dag;
  SCC(G& g) : g(g), used(len(g), 0) { build(); }
  int operator[](int k) { return comp[k]; }
  vi& belong(int i) { return blng[i]; }

 private:
  const G& g;
  vector<vi> rg;
  vi comp, ord;
  vector<bool> used;
  vector<vi> blng;

  void dfs(int idx) {
    if (used[idx]) return;
    used[idx] = true;
    for (auto to : g[idx]) dfs(int(to));
    ord.eb(idx);
  }
  void rdfs(int idx, int cnt) {
    if (comp[idx] != -1) return;
    comp[idx] = cnt;
    for (int to : rg[idx]) rdfs(to, cnt);
  }
  void build() {
    for (int i = 0; i < len(g); i++) dfs(i);
    reverse(all(ord));
    used.clear(), used.shrink_to_fit();
    comp.resize(len(g), -1);
    rg.resize(len(g));
    for (int i = 0; i < len(g); i++) {
      for (auto e : g[i]) {
        rg[e].emplace_back(i);
      }
    }
    int ptr = 0;
    for (int i : ord)
      if (comp[i] == -1) rdfs(i, ptr), ptr++;
    rg.clear(), rg.shrink_to_fit();
    ord.clear(), ord.shrink_to_fit();
    dag.resize(ptr), blng.resize(ptr);
    for (int i = 0; i < (int) len(g); i++) {
      blng[comp[i]].eb(i);
      for (auto& to : g[i]) {
        int x = comp[i], y = comp[to];
        if (x == y) continue;
        dag[x].eb(y);
      }
    }
  }
};