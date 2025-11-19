/*
  Persistent + Dynamic Segment Tree that supports Monoid operation.
  Tested on https://cses.fi/problemset/task/1737/
*/

template <class T, class F>
struct PST {
  struct Node {
    T v;
    Node *l = nullptr, *r = nullptr;
    Node(T v) : v(v) {}
  };
  int n;
  const F f;
  const T I;
  PST(int n, F f, const T& I) : n(n), f(f), I(I) {}
  T get_val(Node* u) const { return u ? u->v : I; }

  Node* apply(Node* prev, int L, int R, int pos, const T& nv) {
    Node* u = new Node(prev ? prev->v : I);
    if (prev) u->l = prev->l, u->r = prev->r;
    if (L == R) {
      u->v = nv;
      return u;
    }
    int M = (L + R) >> 1;
    if (pos <= M) {
      u->l = apply(u->l, L, M, pos, nv);
    } else {
      u->r = apply(u->r, M + 1, R, pos, nv);
    }
    u->v = f(get_val(u->l), get_val(u->r));
    return u;
  }
  // [ql, qr] inclusive
  T query(Node* u, int L, int R, int ql, int qr) const {
    if (!u || qr < L || R < ql) return I;
    if (ql <= L && R <= qr) return u->v;
    int M = (L + R) >> 1;
    return f(query(u->l, L, M, ql, qr), query(u->r, M + 1, R, ql, qr));
  }
};