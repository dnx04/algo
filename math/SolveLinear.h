#include "RowEchelon.h"

vector<ld> SolveLinear(mat& A) {
  int m = A[0].size() - 1;
  auto piv = RowEchelon(A).first;
  if (piv.empty() || piv.back() == m) return {};
  vector<ld> sol(m, 0.);
  for (int i = 0; i < (int)piv.size(); ++i)
    sol[piv[i]] = A[i][m] / A[i][piv[i]];
  return sol;
}