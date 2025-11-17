#include "Point.h"

template <class P>
vector<P> circleLine(P c, double r, P a, P b) {
  P ab = b - a;
  ld s = a.cross(b, c);

  // calculate intersection, return vector<P>
  P p = a + ab * (c - a).dot(ab) / ab.dist2();
  ld h2 = r * r - s * s / ab.dist2();
  if (h2 < 0) return {};
  if (h2 == 0) return {p};
  P h = ab.unit() * sqrt(h2);
  return {p - h, p + h};

  // calculate smaller part area, return ld
  // ld dist = fabs(s) / sqrt(ab.dist2());
  // assert(dist <= r);
  // ld theta = 2.0 * acos(dist / r);
  // ld area = 0.5 * r * r * (theta - sin(theta));
  // return area;
}