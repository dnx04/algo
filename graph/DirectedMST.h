struct DSU {
  vector<int> link;
  DSU(int n) : link(n, -1) {}
  int Find(int x) { return link[x] == -1 ? x : link[x] = Find(link[x]); }
};

struct SkewHeap {
  struct Node { ll key, lazy = 0; int l = -1, r = -1; };
  vector<Node> T;

  void push(int x) {
    if (x == -1 || !T[x].lazy) return;
    for (int y : {T[x].l, T[x].r}) if (y != -1) 
      T[y].lazy += T[x].lazy;
    T[x].key += T[x].lazy, T[x].lazy = 0;
  }
  // Make new node. Returns its index. Indexes go 0, 1, ...
  int New(ll key) { 
    T.push_back(Node{key}); 
    return (int)T.size() - 1;
  }
  // Increment all values in heap p by v
  void Add(int x, ll v) { if (~x) T[x].lazy += v, push(x); }
  // Merge heaps a and b
  int Merge(int a, int b) {
    if (b == -1 || a == -1) return a + b + 1;
    if (T[a].key > T[b].key) swap(a, b);
    int &l = T[a].l, &r = T[a].r;
    push(r); swap(l, r); l = Merge(l, b);
    return a;
  }
  void Pop(int& x) { x = Merge(T[x].l, T[x].r); }
  ll Get(int x) { return T[x].key; }
};

struct Edge { int a, b; ll c; }; 

pair<ll, vector<int>> DMST(int n, int src, vector<Edge> es) {
  // Compress graph - O(M logN)
  SkewHeap H; DSU D(2 * n); int x = 0;
  vector<int> par(2 * n, -1), ins(par), vis(par);
  for (auto e : es) ins[e.b] = H.Merge(ins[e.b], H.New(e.c));
  auto go = [&](int x) { return D.Find(es[ins[x]].a); };
  for (int i = n; ins[x] != -1; ++i) {
    for (; vis[x] == -1; x = go(x)) vis[x] = 0;
    for (; x != i; x = go(x)) {
      int rem = ins[x]; ll w = H.Get(rem); H.Pop(rem);
      H.Add(rem, -w); ins[i] = H.Merge(ins[i], rem);
      par[x] = i; D.link[x] = i;
    }
    for (; ins[x] != -1 && go(x) == x; H.Pop(ins[x]));
  }
  // Expand graph - O(N)
  ll cost = 0; vector<int> ans;
  for (int i = src; i != -1; i = par[i]) vis[i] = 1;
  for (int i = x; i >= 0; --i) {
    if (vis[i]) continue;
    cost += es[ins[i]].c; ans.push_back(ins[i]);
    for (int j = es[ins[i]].b; j != -1 && !vis[j]; j = par[j]) 
      vis[j] = 1;
  }
  return {cost, ans};
}