#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../misc/macros.h"
#include "../graph/Dinic.h"

void solve() {
  int L, R, M;
  cin >> L >> R >> M;

  // Xây dựng đồ thị:
  // 0 -> L-1: Đỉnh trái
  // L -> L+R-1: Đỉnh phải
  // S = L+R, T = L+R+1
  int S = L + R, T = L + R + 1;
  Dinic dinic(T + 1);

  // Nối S -> Left
  for (int i = 0; i < L; ++i) dinic.addEdge(S, i, 1);
  
  // Nối Right -> T
  for (int i = 0; i < R; ++i) dinic.addEdge(L + i, T, 1);

  // Nối Left -> Right (Edges)
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    dinic.addEdge(u, L + v, 1);
  }

  // Tính luồng cực đại = Cặp ghép cực đại
  cout << dinic.calc(S, T) << "\n";

  // Truy vết in kết quả
  // Duyệt qua các đỉnh bên trái (0 -> L-1)
  for (int i = 0; i < L; ++i) {
    for (auto& e : dinic.adj[i]) {
      if (e.to >= L && e.to < L + R && e.c == 0) {
        cout << i << " " << e.to - L << "\n";
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}