#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../misc/macros.h"
#include "../strings/SuffixArray.h"

void solve() {
  string s;
  cin >> s;
  auto sa = SuffixArray(s);
  for (int i = 1; i < sz(sa.sa); ++i) cout << sa.sa[i] << ' ';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}