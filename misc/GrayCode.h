vector<int> gray(int n) {
  vector<int> ret;
  for (int i = 0; i < n; i++) ret.push_back(i ^ (i >> 1));
  return ret;
}
// gray cycle:
// m = 2^k >= n, pick n / 2 first and n / 2 last elements