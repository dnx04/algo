#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../misc/macros.h"
#include "../strings/SuffixArray.h"

void solve() {
  string s;
  cin >> s;
  i64 n = sz(s);
  auto sa = SuffixArray(s);
  i64 ans = n * (n + 1) / 2;
  cout << ans - accumulate(all(sa.lcp), 0ll);
}

int main() {
  solve();
}