int Freivalds(Mat a, Mat b, Mat c) {
  int n = a.n, iteration = 40;
  Mat zero(n, 1), r(n, 1);
  while (iteration--) {
    for (int i = 0; i < n; i++) r.a[i][0] = rnd() % 2;
    Mat ans = (a * (b * r)) - (c * r);
    if (ans != zero) return 0;
  }
  return 1;
}