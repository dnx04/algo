struct SuffixArray {
  vector<int> sa, lcp, rank;
  SuffixArray(string s, int lim = 256) {
    int n = s.size() + 1, k = 0, a, b;
    s.push_back(0);
    vector<int> y(n), cnt(max(n, lim));
    sa.resize(n), lcp.resize(n), rank.resize(n);
    for (int i = 0; i < n; ++i) rank[i] = s[i];
    iota(sa.begin(), sa.end(), 0);
    
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j;
      iota(all(y), n - j);
      for (int i = 0; i < n; ++i)
        if (sa[i] >= j) y[p++] = sa[i] - j;
      fill(all(cnt), 0);
      for (int i = 0; i < n; ++i) cnt[rank[i]]++;
      for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];
      for (int i = n; i--;) sa[--cnt[rank[y[i]]]] = y[i];
      swap(rank, y), p = 1, rank[sa[0]] = 0;
      for (int i = 1; i < n; ++i) {
        a = sa[i - 1], b = sa[i];
        int val_a = (a + j < n) ? y[a + j] : -1;
        int val_b = (b + j < n) ? y[b + j] : -1;
        rank[b] = (y[a] == y[b] && val_a == val_b) ? p - 1 : p++;
      }
    }
    
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
      for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
  }
};