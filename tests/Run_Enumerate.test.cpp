#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include "../misc/macros.h"
#include "../ds/RMQ.h"
#include "../strings/SuffixArray.h"

struct Run {
  int t, l, r;
  // So sánh để sort candidates: ưu tiên l, r, rồi đến t nhỏ nhất
  bool operator<(const Run& other) const {
    if (l != other.l) return l < other.l;
    if (r != other.r) return r < other.r;
    return t < other.t;
  }
  // So sánh để sort output cuối cùng (theo yêu cầu đề bài: thường là t, l, r)
  static bool compareOutput(const Run& a, const Run& b) {
    if (a.t != b.t) return a.t < b.t;
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
  }
};

template <class R>
int get_lcp(const SuffixArray& sa, R& rmq, int i, int j) {
  if (i == j) return sz(sa.sa) - 1 - i;
  int l = sa.rank[i], r = sa.rank[j];
  if (l > r) swap(l, r);
  return rmq.query(l + 1, r + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = sz(s);

  auto min_func = [](int a, int b) { return min(a, b); };

  SuffixArray sa(s);
  RMQ rmq(sa.lcp, min_func);

  string s_rev = s;
  reverse(all(s_rev));
  SuffixArray sa_rev(s_rev);
  RMQ rmq_rev(sa_rev.lcp, min_func);

  vector<Run> candidates;

  for (int t = 1; t <= n / 2; ++t) {
    for (int i = 0; i + t < n; i += t) {
      int j = i + t;
      int l1 = get_lcp(sa, rmq, i, j);
      int l2 = 0;
      if (i > 0) l2 = get_lcp(sa_rev, rmq_rev, n - i, n - j);

      if (l1 + l2 >= t && l2 < t) {
        // Lưu lại ứng viên (t, l, r)
        candidates.push_back({t, i - l2, i - l2 + t + l1 + l2});
      }
    }
  }

  // BƯỚC 1: Sort candidates theo (l, r, t)
  sort(all(candidates));

  // BƯỚC 2: Lọc trùng (giữ t nhỏ nhất cho cùng l, r)
  vector<Run> result;
  for (auto& run : candidates) {
    if (!result.empty()) {
      Run& last = result.back();
      if (last.l == run.l && last.r == run.r) continue;  // Đã có run cùng l,r với t nhỏ hơn -> Bỏ qua
    }
    result.push_back(run);
  }

  // BƯỚC 3: Sort kết quả theo (t, l, r) để in ra
  sort(all(result), Run::compareOutput);

  cout << sz(result) << "\n";
  for (auto& run : result) {
    cout << run.t << " " << run.l << " " << run.r << "\n";
  }
}