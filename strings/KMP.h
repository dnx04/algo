vi pi(const string& s) {
  vi p(len(s));
  for (int i = 1; i < len(s); ++i) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}