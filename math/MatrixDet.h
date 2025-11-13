#include "RowEchelon.h"

ld Determinant(mat& A) {
  int n = A.size(); 
  ld det = RowEchelon(A).second;
  for (int i = 0; i < n; ++i) 
    det *= A[i][i];
  return det;
}