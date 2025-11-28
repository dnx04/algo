#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include "../misc/macros.h"
#include "../math/Poly.h"

vector<Fp> fact, invFact;
void init_fact(int n) {
  fact.resize(n + 1);
  invFact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
  invFact[n] = fact[n].inv();
  for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1);
}

Fp nCk(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * invFact[k] * invFact[n - k];
}

void solve() {
  // Stirling loại 1: Hệ số của đa thức x(x-1)(x-2)...(x-N+1)
  // Dùng chia để trị O(N log^2 N) vì N nhỏ
  int n;
  cin >> n;
  if(n == 0) {
    cout << 1;
    return;
  }
  deque<Poly> dq;
  for (int i = 0; i < n; ++i) {
    // Đa thức (x - i)
    dq.push_back(Poly({-i, 1}));
  }

  while(sz(dq) > 1) {
    auto f = dq.front();
    dq.pop_front();
    auto g = dq.front();
    dq.pop_front();
    dq.push_back(f * g);
  }

  Poly res = dq.back();
  for (int i = 0; i <= n; ++i) {
    cout << res[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}