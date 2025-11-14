#include "Point.h"

template <class T>
T polygonArea2(vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  for (int i = 0; i < n; ++i)i, 0, sz(v) - 1) a += v[i].cross(v[i + 1]);
  return a;
}