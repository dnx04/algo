// N: số phần tử
// cost(i, j): chi phí gộp đoạn [i, j]
template <class F>
i64 knuth(int N, F cost) {
  const i64 INF = 1e18;
  vector<vector<i64>> dp(N + 2, vector<i64>(N + 2, 0));
  vector<vector<int>> opt(N + 2, vector<int>(N + 2, 0));
  // Khởi tạo base case: đoạn độ dài 1
  for (int i = 1; i <= N; ++i) dp[i][i] = cost(i, i), opt[i][i] = i;
  // Duyệt theo độ dài len
  for (int len = 2; len <= N; ++len) {
    for (int i = 1; i <= N - len + 1; ++i) {
      int j = i + len - 1;
      dp[i][j] = INF;
      i64 c = cost(i, j);
      for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); ++k) {
        i64 curr = dp[i][k] + dp[k + 1][j] + c;
        if (curr < dp[i][j]) dp[i][j] = curr, opt[i][j] = k;
      }
    }
  }
  return dp[1][N];
}