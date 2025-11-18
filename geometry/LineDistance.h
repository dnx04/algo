#include "Point.h"

template <class P>
ld lineDist(const P& a, const P& b, const P& p) {
  return (ld) (b - a).cross(p - a) / (b - a).dist();
}