#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>

using namespace std;

#include "../modint.hpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  Mod<1000000007> m;
  int n;
  cin >> m >> n;
  cout << (m ^ n) << '\n';
}