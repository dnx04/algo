#include "HLD.h"

template <class G>
struct VirtualTree : HLD<G> {
  using HLD<G>::pos, HLD<G>::len, HLD<G>::lca, HLD<G>::n;
  vector<vi> adj;  // (Directed: Parent -> Child)
  VirtualTree(const G& g, int root = 0) : HLD<G>(g, root), adj(n) {}
  // Input: danh sách đỉnh cần dựng cây.
  // Output: danh sách đỉnh của cây ảo (đã sort theo DFS order, bao gồm cả LCAs).
  //        Đỉnh đầu tiên của vector trả về là Gốc của cây ảo.
  vi build(vi& nodes) {
    auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
    sort(all(nodes), cmp);
    int k = len(nodes);
    for (int i = 0; i < k - 1; ++i) nodes.pb(lca(nodes[i], nodes[i + 1]));
    sort(all(nodes), cmp);
    nodes.erase(unique(all(nodes)), nodes.end());
    for (int u : nodes) adj[u].clear();
    vi st;
    for (int u : nodes) {
      // Check if st.back() is ancestor of u
      while (len(st) && !(pos[st.back()] <= pos[u] && pos[u] < pos[st.back()] + len[st.back()]))
        st.pop_back();
      if (len(st)) adj[st.back()].pb(u);
      st.pb(u);
    }
    return nodes;
  }
};
