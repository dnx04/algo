template <typename T>
struct affine {
  T a, b;
  constexpr affine() : a(1), b(0) {}
  constexpr affine(T a, T b) : a(a), b(b) {}
  T operator()(T x) { return a * x + b; }
  affine operator()(const affine& f) const {
    return f * (*this);
  }
  affine operator*(const affine& g) const {
    return {a * g.a, b * g.a + g.b};
  }
};