#include "RowEchelon.h"

bool Invert(mat& A) {
  int n = A.size(); // assert(n == A[0].size()); 
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      A[i].push_back(i == j);
  auto [piv, sgn] = RowEchelon(A);
  if ((int)piv.size() < n || piv.back() >= n) return false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      // For adjunct, do A[i][j + n] *= sgn instead.
      A[i][j + n] /= A[i][i]; 
    A[i].erase(A[i].begin(), A[i].begin() + n);
  }
  return true;
}