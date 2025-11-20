#include "HLD.h"

template <typename G>
struct AuxiliaryTree {
  G g;
  HLD<G> hld;
  AuxiliaryTree(const G& g, int root = 0) : g(g), hld(g, root) {}
  vi get(vi ps) {
    if (ps.empty()) return {};
    auto comp = [&](int i, int j) { return hld.down[i] < hld.down[j]; };
    sort(all(ps), comp);
    for (int i = 0, ie = sz(ps); i + 1 < ie; i++) {
      ps.eb(hld.lca(ps[i], ps[i + 1]));
    }
    sort(all(ps), comp);
    ps.erase(unique(all(ps)), end(ps));
    vector<vi> aux(sz(ps));
    vi rs;
    rs.eb(0);  // root ?
    for (int i = 1; i < sz(ps); i++) {
      int l = hld.lca(ps[rs.back()], ps[i]);
      while (ps[rs.back()] != l) rs.pop_back();
      aux[rs.back()].eb(i), rs.eb(i);
    }
    return aux;
  }
};
