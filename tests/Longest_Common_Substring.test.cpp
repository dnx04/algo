#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../misc/macros.h"
#include "../strings/SuffixArray.h"

void solve() {
  string S, T;
  cin >> S >> T;
  SuffixArray sa(S + '$' + T);  // Nối chuỗi
  int n = sz(S);
  int maxL = 0, pS = -1, pT = -1;

  // Duyệt mảng LCP để tìm max
  for (int i = 1; i < sz(sa.lcp); ++i) {
    int u = sa.sa[i], v = sa.sa[i - 1];

    // Kiểm tra u, v có nằm ở 2 xâu khác nhau không (một cái < n, một cái > n)
    if ((u < n) != (v < n)) {
      if (sa.lcp[i] > maxL) {
        maxL = sa.lcp[i];
        pS = (u < n ? u : v);          // Vị trí bên S
        pT = (u > n ? u : v) - n - 1;  // Vị trí bên T (trừ độ dài S và dấu $)
      }
    }
  }

  if (maxL > 0) {
    cout << pS << " " << pS + maxL << " " << pT << " " << pT + maxL;
  } else {
    cout << "0 0 0 0";
  }
}

int main() {
  solve();
}