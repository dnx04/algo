struct DSU {
 public:
  DSU(int _n) : n(_n), p(_n, -1) {}

  int merge(int a, int b) {
    int x = head(a), y = head(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }

  bool same(int a, int b) { return head(a) == head(b); }

  int head(int a) {
    if (p[a] < 0) return a;
    return p[a] = head(p[a]);
  }

  int size(int a) { return -p[head(a)]; }

 private:
  int n;
  vector<int> p;
};