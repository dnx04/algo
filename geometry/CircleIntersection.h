#include "Point.h"

typedef Point<ld> P;
bool circleInter(P a, P b, ld r1, ld r2, pair<P, P>* out) {
  if (a == b) {
    assert(r1 != r2);
    return false;
  }
  P vec = b - a;
  ld d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2,
     p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2) return false;
  P mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  *out = {mid + per, mid - per};
  return true;
}