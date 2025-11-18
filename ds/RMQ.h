template <class T, class F>
struct RMQ {
  vector<vector<T>> jmp;
  const F f;
  RMQ(const vector<T>& V, F f) : jmp(1, V), f(f) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.eb(sz(V) - pw * 2 + 1);
      for (int j = 0; j < sz(jmp[k]); ++j) jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  // [a, b)
  T query(int a, int b) {
    assert(a < b);
    int dep = 31 - __builtin_clz(b - a);
    return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};