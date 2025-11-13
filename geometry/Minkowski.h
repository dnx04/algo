#include "Point.h"

vector<Point> MinkowskiSum(vector<Point> P, vector<Point> Q) {
  int n = P.size(), m = Q.size();
  vector<Point> R = {P[0] + Q[0]};
  for (int i = 1, j = 1; i < n || j < m; ) {
    if (i < n && (j == m || cross(P[i] - P[i - 1], Q[j] - Q[j - 1]) > 0)) {
      R.push_back(R.back() + P[i] - P[i - 1]);
      ++i;
    } else {
      R.push_back(R.back() + Q[j] - Q[j - 1]);
      ++j;
    }
  }
  return R;
}