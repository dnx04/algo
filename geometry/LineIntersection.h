#include "Point.h"
#include "Line.h"

template <class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0)  // if parallel
    return {-(s1.cross(e1, s2) == 0), P(0, 0)};
  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}

tuple<T4, T4, T2> LineIntersection(Line m, Line n) {
  T2 d = (T2)m.a * n.b - (T2)m.b * n.a; // assert(d);
  T4 x = (T4)m.c * n.b - (T4)m.b * n.c; 
  T4 y = (T4)m.a * n.c - (T4)m.c * n.a;
  return {x, y, d}; // (x/d, y/d) is intersection. 
}