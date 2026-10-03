#include "Point.h"

typedef Point<ld> P;
P polygonCenter(const vector<P>& v) {
  P res(0, 0);
  ld A = 0;
  for (int i = 0, j = len(v) - 1; i < len(v); j = i++) {
    res = res + (v[i] + v[j]) * v[j].cross(v[i]);
    A += v[j].cross(v[i]);
  }
  return res / A / 3;
}