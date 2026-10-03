vi Z(const string& S) {
  vi z(len(S));
  int l = -1, r = -1;
  for (int i = 1; i < len(S); ++i) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < len(S) && S[i + z[i]] == S[z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}