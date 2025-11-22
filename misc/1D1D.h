// n: số phần tử (tính dp từ 1 đến n)
// cost: hàm tính chi phí cost(j, i)
template <class F>
vector<i64> solve_1d1d(int n, F cost) {
  vector<i64> dp(n + 1);
  dp[0] = 0;
  // tuple: {index nguồn, biên trái, biên phải}
  struct State {
    int u, l, r;
  };
  deque<State> dq;
  dq.push_back({0, 1, n});
  // Hàm tiện ích tính giá trị khi chuyển từ j -> i
  auto val = [&](int j, int i) { return dp[j] + cost(j, i); };
  for (int i = 1; i <= n; ++i) {
    // 1. Lấy giá trị tối ưu cho i từ đầu deque
    dp[i] = val(dq.front().u, i);
    // 2. Cập nhật khoảng cover của phần tử đầu
    if (dq.front().r == i) dq.pop_front();
    else dq.front().l = i + 1;
    // 3. Thêm i vào deque làm ứng viên mới
    // Bỏ những ứng viên ở cuối nếu i tốt hơn họ ngay tại điểm bắt đầu l
    while (!dq.empty() && val(i, dq.back().l) <= val(dq.back().u, dq.back().l)) dq.pop_back();
    // Nếu deque rỗng, i thắng tất cả -> cover phần còn lại
    if (dq.empty()) {
      dq.push_back({i, i + 1, n});
    } else {
      // Nếu i thắng ứng viên cuối tại điểm kết thúc r, ta tìm điểm cắt
      // Nếu không thắng tại r, nghĩa là i không bao giờ vượt qua được ứng viên này -> bỏ qua i
      auto& back = dq.back();
      if (back.r > i && val(i, back.r) < val(back.u, back.r)) {
        int l = back.l, r = back.r, pos = r + 1;
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (val(i, mid) < val(back.u, mid)) pos = mid, r = mid - 1;
          else l = mid + 1;
        }
        back.r = pos - 1;
        dq.push_back({i, pos, n});
      }
    }
  }
  return dp;
}