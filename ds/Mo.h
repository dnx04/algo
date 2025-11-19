const int sz = 850; // should be sqrt(3/2 * N)
struct Query {
  int l, r, idx;
  bool operator<(const Query& o) {
    if (l / sz != o.l / sz) return l / sz < o.l / sz;
    else {
      if ((l / sz) & 1) return r / sz < o.r / sz;
      else return r / sz > o.r / sz;
    }
  };
};
// handle [l, r] inclusive:
// int pl = 0, pr = -1;
// for (auto [l, r, idx] : qry) {
//   while (pr < r) add(x[++pr]);
//   while (l < pl) add(x[--pl]);
//   while (pl < l) rem(x[pl++]);
//   while (r < pr) rem(x[pr--]);
//   ans[idx] = res;
// }