const int len = 850;  // should be sqrt(3/2 * N)
struct Query {
  int l, r, idx;
  bool operator<(const Query& o) {
    if (l / len != o.l / len)
      return l / len < o.l / len;
    else {
      if ((l / len) & 1)
        return r / len < o.r / len;
      else
        return r / len > o.r / len;
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