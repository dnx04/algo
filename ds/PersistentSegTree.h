/*
  Persistent Segment Tree that supports Monoid operation.
  Tested on https://cses.fi/problemset/task/1737/

  Usage:
  - monoids = {f, id}, here f = u + v and id = 0:

  PST pst((n + q) * log(n) * 2, f, 0ll);
  vector<PST<ll, decltype(f)>*> roots;
  roots.reserve(q + 1);
  roots.push_back(pst.build(0, n - 1, a));
*/


template <class T, class F>
struct PST {
  T v;
  int n;
  const F f;
  const T I;
  PST *l = nullptr, *r = nullptr;
  PST(int n, F f, const T& I) : n(n), f(f), I(I) {}
  PST* build(int L, int R, const vector<T>& a) {
    PST* u = new PST(n, f, I);
    if (L == R) {
      u->v = a[L];
    } else {
      int M = (L + R) >> 1;
      u->l = build(L, M, a);
      u->r = build(M + 1, R, a);
      u->v = f(u->l->v, u->r->v);
    }
    return u;
  }

  PST* update(PST* prev, int L, int R, int pos, const T& nv) {
    PST* u = new PST(*prev);
    if (L == R) {
      u->v = nv;
    } else {
      int M = (L + R) >> 1;
      if (pos <= M)
        u->l = update(prev->l, L, M, pos, nv);
      else
        u->r = update(prev->r, M + 1, R, pos, nv);
      u->v = f(u->l->v, u->r->v);
    }
    return u;
  }

  T query(PST* u, int L, int R, int ql, int qr) const {
    if (!u || qr < L || R < ql) return I;
    if (ql <= L && R <= qr) return u->v;
    int M = (L + R) >> 1;
    return f(query(u->l, L, M, ql, qr), query(u->r, M + 1, R, ql, qr));
  }
};
