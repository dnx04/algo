template <typename T>
void FST(vector<T>& a, bool inv, string type) {
  for (int n = sz(a), step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step)
      for (int j = i; j < i + step; ++j) {
        T &u = a[j], &v = a[j + step];
        if (type == "and")
          tie(u, v) = inv ? tuple{v - u, u} : tuple{v, u + v};
        else if (type == "or")
          tie(u, v) = inv ? tuple{v, u - v} : tuple{u + v, u};
        else if (type == "xor")
          tie(u, v) = tuple{u + v, u - v};
      }
  }
  if (inv && type == "xor")
    for (T& x : a) x /= sz(a);
}
template <typename T>
vector<T> conv(vector<T> a, vector<T> b, string type) {
  FST(a, 0, type);
  FST(b, 0, type);
  for (int i = 0; i < sz(a); ++i) a[i] *= b[i];
  FST(a, 1, type);
  return a;
}