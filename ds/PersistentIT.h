struct PST {
  struct Node {
    ll v;
    Node *l, *r;
    Node(ll v = 0, Node* l = nullptr, Node* r = nullptr) : v(v), l(l), r(r) {}
  };
  int n;
  PST(int _n) : n(n) {}
  Node* build(int L, int R, vector<ll>& a) {
    Node* u = new Node();
    if (L == R) {
      u->v = a[L];
    } else {
      int M = (L + R) >> 1;
      u->l = build(L, M, a);
      u->r = build(M + 1, R, a);
      u->v = u->l->v + u->r->v;
    }
    return u;
  }
  Node* update(Node* prev, int L, int R, int pos, ll nv) {
    Node* u = new Node(*prev);
    if (L == R) {
      u->v = nv;
    } else {
      int M = (L + R) >> 1;
      if (pos <= M) {
        u->l = update(prev->l, L, M, pos, nv);
      } else {
        u->r = update(prev->r, M + 1, R, pos, nv);
      }
      u->v = u->l->v + u->r->v;
    }
    return u;
  }
  ll query(Node* u, int L, int R, int ql, int qr) {
    if (!u || qr < L || R < ql) return 0;
    if (ql <= L && R <= qr) return u->v;
    int M = (L + R) >> 1;
    return query(u->l, L, M, ql, qr) + query(u->r, M + 1, R, ql, qr);
  }
};
