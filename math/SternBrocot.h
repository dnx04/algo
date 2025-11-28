struct Frac { i64 p, q; };
using Path = vector<pair<char, i64>>;

namespace SternBrocot {
  // 1. Encode: 1/1 -> p/q
  Path encode(i64 p, i64 q) {
    Path res;
    while (p != q) {
      i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);
      res.push_back({p < q ? 'L' : 'R', k});
      if (p < q) q -= k * p; else p -= k * q;
    }
    return res;
  }
  // 2. Decode: Path -> Frac
  Frac decode(const Path& path) {
    i64 lp = 0, lq = 1, rp = 1, rq = 0;
    for (auto [c, k] : path)
      if (c == 'L') rp += k * lp, rq += k * lq;
      else          lp += k * rp, lq += k * rq;
    return {lp + rp, lq + rq};
  }
  // 3. LCA: a/b vs c/d
  Frac lca(i64 a, i64 b, i64 c, i64 d) {
    Path p1 = encode(a, b), p2 = encode(c, d), res;
    for (int i = 0; i < min((int)p1.size(), (int)p2.size()) && p1[i].first == p2[i].first; ++i)
      res.push_back({p1[i].first, min(p1[i].second, p2[i].second)}),
      p1[i].second == p2[i].second ? 0 : (i = p1.size());
    return decode(res);
  }
  // 4. Ancestor: Trả về nút ở độ sâu k trên đường đi từ 1/1 đến p/q
  // k=0 -> 1/1, k=1 -> con trực tiếp của 1/1...
  Frac ancestor(i64 k, i64 p, i64 q) {
    Path path = encode(p, q);
    i64 lp = 0, lq = 1, rp = 1, rq = 0;
    for (auto [c, step] : path) {
      i64 take = min(k, step);
      if (c == 'L') rp += take * lp, rq += take * lq;
      else          lp += take * rp, lq += take * rq;
      k -= take;
      if (k == 0) return {lp + rp, lq + rq};
    }
    return {-1, -1}; // k lớn hơn độ sâu của p/q
  }
  // 5. Range: Tìm khoảng con (L, R) chứa p/q
  pair<Frac, Frac> range(i64 p, i64 q) {
    if (p == 0) return {{0, 1}, {1, 0}};
    i64 lp = 0, lq = 1, rp = 1, rq = 0;
    while (p != q) {
      i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);
      if (p < q) rp += k * lp, rq += k * lq, q -= k * p;
      else       lp += k * rp, lq += k * rq, p -= k * q;
    }
    return {{lp, lq}, {rp, rq}};
  }
  // 6. Bound: Tìm {L, R} sát nhất trên SBT thỏa mãn giới hạn và hàm f
  // f(Frac) -> bool: hàm đơn điệu trên cây (VD: f(x) = x <= target)
  // Trả về {L, R} là 2 phân số kẹp giữa ranh giới T/F của f
  template <class Func>
  pair<Frac, Frac> bound(Func f, i64 maxp, i64 maxq) {
    Frac l{0, 1}, r{1, 0}, m;
    int dir = 1; 
    if (f({1, 1}) == f(l)) l = {1, 1}; else r = {1, 1}, dir = 0;
    while (true) {
      Frac &cur = dir ? l : r, &del = dir ? r : l;
      i64 k = 0;
      for (i64 step = 1; step; ) {
        i64 nk = k + step;
        i64 np = cur.p + nk * del.p, nq = cur.q + nk * del.q;
        if (np <= maxp && nq <= maxq && f({np, nq}) == dir) k = nk, step *= 2;
        else step /= 2;
      }
      cur.p += k * del.p, cur.q += k * del.q;
      m = {l.p + r.p, l.q + r.q};
      if (m.p > maxp || m.q > maxq) break;
      if (f(m)) l = m, dir = 1; else r = m, dir = 0;
    }
    return {l, r};
  }
}