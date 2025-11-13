vi pi(const string& s) {
  vi p(sz(s));
  for (int i = 1; i < sz(s); ++i) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}