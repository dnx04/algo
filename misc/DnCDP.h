// N: số phần tử, K: số đoạn chia
// cost(l, r): trả về chi phí đoạn [l, r]
template <class F>
i64 solve_dnc(int N, int K, F cost) {
  const i64 INF = 1e18;
  vector<i64> dp_before(N + 1, INF), dp_cur(N + 1);
  // Khởi tạo tầng k=1
  for (int i = 1; i <= N; ++i) dp_before[i] = cost(1, i);
  // Hàm đệ quy xử lý từng tầng
  auto compute = [&](auto&& self, int L, int R, int optL, int optR) -> void {
    if (L > R) return;
    int mid = (L + R) / 2;
    int best_k = -1;
    dp_cur[mid] = INF;
    // Giới hạn k: từ optL đến min(mid - 1, optR)
    for (int k = optL; k <= min(mid - 1, optR); ++k) {
      i64 val = dp_before[k] + cost(k + 1, mid);
      if (val < dp_cur[mid]) {
        dp_cur[mid] = val;
        best_k = k;
      }
    }
    self(self, L, mid - 1, optL, best_k);
    self(self, mid + 1, R, best_k, optR);
  };
  for (int k = 2; k <= K; ++k) compute(compute, 1, N, 1, N), dp_before = dp_cur;
  return dp_before[N];
}