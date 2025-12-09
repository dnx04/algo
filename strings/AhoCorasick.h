struct AhoCorasick {
  static const int K = 26;
  struct Node {
    int link = 0, el = 0; // suffix link, exit link
    int nxt[K];
    vector<int> ids; // pattern indices
    Node() { memset(nxt, -1, sizeof(nxt)); }
  };
  vector<Node> g;
  AhoCorasick() { g.eb(); }
  void insert(const string& s, int id) {
    int u = 0;
    for (char c : s) {
      int& v = g[u].nxt[c - 'a'];
      if (v == -1) v = g.size(), g.eb();
      u = v;
    }
    g[u].ids.pb(id);
  }
  void build() {
    queue<int> q; q.push(0);
    while (q.size()) {
      int u = q.front(); q.pop();
      int l = g[u].link;
      if (u) g[u].el = g[l].ids.empty() ? g[l].el : l;

      for (int i = 0; i < K; ++i) {
        int& v = g[u].nxt[i];
        int next_l = u ? g[l].nxt[i] : 0;
        if (v == -1) v = next_l; // Automaton: O(1) transition
        else g[v].link = next_l, q.push(v);
      }
    }
  }
  vector<vector<int>> find_all(const string& text) {
    int u = 0;
    vector<vector<int>> res(text.size());
    for (int i = 0; i < text.size(); ++i) {
      u = g[u].nxt[text[i] - 'a'];
      for (int v = g[u].ids.empty() ? g[u].el : u; v; v = g[v].el)
        for (int id : g[v].ids) res[i].pb(id);
    }
    return res;
  }
};