#import "icpc.typ": *

#show: doc => icpc(
  team: [Quattuorvigintillion - University of Engineering and Technology, VNU],
  doc,
)

// #file("misc/c_cpp_properties.json")
// #file("misc/tasks.json")
// #file("misc/launch.json")

= Notes

== Lucas

Với $n = n_k p^k + n_(k-1) p^(k-1) + ... + n_0$ và $m = m_k p^k + m_(k-1) p^(k-1) + ... + m_0$. Ta có $binom(n, m) = product_(i=0)^k binom(n_i, m_i) mod p$.

== Pisano

$pi(n)$ là chu kì modulo $n$ của dãy Fibonacci:

1. $pi(a b) = lcm(pi(a), pi(b))$ với $(a, b) = 1$
2. $pi(p^n) divides p^(n - 1)pi(p)$: duyệt ước
3. $p > 5, p equiv plus.minus 1 (mod 5)$, thì $pi(p) divides p - 1$
4. $p > 5, p equiv plus.minus 2 (mod 5)$, thì $pi(p) divides 2(p + 1)$

== Hàm sinh

=== Catalan

$ C_n = 1 / (n + 1) binom(2n, n), C_(n + 1) = sum_(i=0)^n C_i C_(n - i) $

- Số lượng cây nhị phân (có gốc) mà mỗi nút có đúng 0 hoặc 2 con (không có nút 1 con), và tổng cộng có $n+1$ lá.
- Số cách chia một đa giác lồi có $n+2$ cạnh thành $n$ tam giác bằng cách vẽ các đường chéo không cắt nhau.
- Số lượng hoán vị của ${1, dots, n}$ không tồn tại các chỉ số $i < j < k$ sao cho $a_j < a_k < a_i$.
- Số cách vẽ các dây cung không cắt nhau nối $2n$ điểm trên đường tròn.
- Số lượng dãy số nguyên $a_1, a_2, dots, a_n$ thỏa mãn $a_i <= i$.

=== Bell

Đếm số cách *phân hoạch một tập hợp* gồm $n$ phần tử dán nhãn (phân biệt) thành các tập con không rỗng rời nhau.

$ E(x) = exp(e^x - 1) = sum_(n=0)^infinity B_n frac(x^n, n!) $

Hàm sinh $exp(e^x - 1)$ thể hiện cấu trúc "tập hợp của các tập hợp" (set of sets).

=== Partition

Đếm số cách *phân hoạch một số nguyên* $n$ thành tổng các số nguyên dương (không quan trọng thứ tự).
$ P(x) = sum_(n=0)^infinity p(n) x^n = product_(k=1)^infinity frac(1, 1 - x^k) $

Mỗi nhân tử $1/(1-x^k) = 1 + x^k + x^(2k) + ...$ đại diện cho việc chọn số $k$ bao nhiêu lần (0 lần, 1 lần, 2 lần...).

Tính mẫu số bằng định lý ngũ giác Euler:

$ product_(n=1)^infinity (1 - x^n) = sum_(k=-infinity)^infinity (-1)^k x^(k(3k-1) / 2) $
$ = 1 - x - x^2 + x^5 + x^7 - x^12 - x^15 + ... $

=== Stirling loại 1

- *Không dấu* $|s(n, k)|$: Đếm số hoán vị của $n$ phần tử phân biệt sao cho hoán vị đó có đúng $k$ chu trình.
- *Có dấu* $s(n, k)$: Là các hệ số của $x(x-1)dots(x-n+1)$ (giai thừa giảm). Dấu $(-1)^(n-k)$ thể hiện tính chẵn lẻ của hoán vị.

- Trường hợp Fixed $n$ (OGF):
  $ sum_(k=0)^n s(n, k) x^k = (x)_n = x(x-1)(x-2)...(x-n+1) $

- Trường hợp Fixed $k$ (EGF theo $n$):
$ sum_(n=k)^infinity s(n, k) frac(x^n, n!) = frac((ln(1+x))^k, k!) $

=== Stirling loại 2

Đếm số cách phân hoạch một tập hợp gồm $n$ phần tử *phân biệt* thành đúng $k$ tập con *không rỗng* và *không phân biệt* thứ tự các tập con đó.

- Trường hợp Fixed $n$:
$
  sum_(k=0)^n S_2(n, k) x^k = underbrace((sum_(i=0)^infinity frac((-1)^i, i!) x^i), A(x)) dot underbrace((sum_(j=0)^infinity frac(j^n, j!) x^j), B(x))
$

- Trường hợp Fixed $k$ (EGF):
$ sum_(n=k)^infinity S_2(n, k) frac(x^n, n!) = frac((e^x - 1)^k, k!) $

== Bổ đề Burnside

Đặt $G$ là nhóm hữu hạn tác động lên tập $X$. Với mỗi $g in G$, gọi $X^g$ là tập các điểm bất định bởi g (${ x ∈ X | g.x = x }$). Số quỹ đạo có thể có là:

$ lr(|X/G|) = 1/lr(|G|) sum_(g in G) |X^g| $

== Định lý Pick

Cho một đa giác có các điểm nguyên. Gọi $i$ là số điểm nguyên nằm trong đa giác, và $b$ là số điểm nguyên năm trên cạnh. Diện tích của đa giác là: $A = i + b/2 - 1$.

== Frobenius

$ g = (F + 1) / 2, quad F = (n - 1)P - sum_{i=1}^n (P / p_i) $

= Toán

#file("math/ModInt.h")
#file("math/MillerRabin.h", description: [
  Kiểm tra số nguyên tố nhanh, *chắc chắn* đúng trong số nguyên 64 bit.
])
#file("math/Matrix.h", description: [
  Ma trận vuông, hỗ trợ nhân, luỹ thừa, khử Gauss, định thức và nghịch đảo.
  Chú ý rằng nhân ma trận với vector là $O(n^2)$.
])
#file("math/ModLog.h", description: [
  Tìm $x > 0$ nhỏ nhất sao cho $a^x = b mod m$, hoặc $-1$. `modLog(a,1,m)` trả về order của $a$ trong $ZZ^*_m$. Độ phức tạp $O(sqrt(m))$.
])
#file("math/ModSQRT.h", description: [
  Tìm căn bậc hai modulo $p$ nguyên tố trong trung bình $O(log p)$.
])
#file("math/Factor.h", description: [
  Tìm một ước của $n$ nhanh trong $O(root(4, n) log n)$. Phân tích đệ quy $n$ thành thừa số nguyên tố.
])
#file("math/CRT.h", description: [
  Duy trì hệ phương trình đồng dư tổng quát (kể cả modulo không nguyên tố cùng nhau).
])
#file("math/DivModSum.h", description: [
  Tính $sum_(i = 0)^(n - 1) (a + i times d) / m$ và $sum_(i = 0)^(n - 1) (a + i times d) mod m$. Độ phức tạp $O(log N)$
])
#file("math/FST.h", description: [
  Tính tích chập AND, OR, XOR.
])
#file("math/ZetaMobius.h")
#file("math/Poly.h", description: [
  Các phép toán trên đa thức + NTT.
])
#file("math/BerlekampMassey.h", description: [
  Phục hồi một dãy truy hồi cấp $n$ từ $2n$ số hạng đầu tiên trong $O(n^2)$.
])
#file("math/Lagrange.h", description: [
  Tìm đa thức bậc $n - 1$ qua $n$ điểm trong $O(n^2)$. Vẫn đúng trong trường modulo.
])
#file("math/SumPowerPoly.h", description: [
  Tính $sum_(i = 0)^infinity r^i i^d$ và $sum_(i = 0)^(n - 1) r^i i^d$.
])
#file("math/Min25.h", description: [
  Sàng Min25 với độ phức tạp $O(N^(3/4) log N)$. Có thể dùng để tính $pi (N)$ và tổng tiền tố hàm nhân tính bất kì với $N <= 10^(12)$.
])
#file("math/SternBrocot.h", description: [
  Các hàm để duyệt phân số và chặt nhị phân phân số.
])
#file("math/XorBasis.h", description: [
  Duy trì XorBasis có tổng trọng số lớn nhất, và tính giao.
  1. Số tập con xor khác nhau của mảng = $2^(|S|)$ với $|S|$ là cỡ của basis.
  2. Tập con có xor lớn nhất: `if ((res ^ basis[b]) > res) res ^= basis[b];`
])

== Frievalds

Kiểm tra tích 2 ma trận $A, B$ có bằng $C$ không trong $O(k n^2)$ với xác suất $2^(-k)$. Sinh ngẫu nhiên vector cột nhị phân $r$ và kiểm tra xem $A B r - C r$ có bằng vector 0 không.

= Cấu trúc dữ liệu

#file("ds/DSU.h")
#file("ds/Fenwick.h")
// #file("ds/SegTree.h")
// #file("ds/LazySegTree.h")
#file("ds/RMQ.h")
#file("ds/HLD.h", description: [
  HLD cho phép truy vấn cả đường đi và cây con cùng lúc.
  1. `idx(x)`: trả về vị trí của đỉnh `x` trong quá trình duyệt DFS.
  2. `query_subtree(x)`: trả về đoạn `[l, r)` tương ứng với cây con của `x`.
  3. `query_path(a, b)`: phân hoạch đường đi từ `a` đến `b` thành các đoạn liên tiếp trong mảng DFS. Sau đó duyệt qua từng đoạn này để cập nhật Segment Tree.
])
#file("ds/VirtualTree.h")
#file("ds/PersistentSegTree.h")
#file("ds/DSURollback.h")
#file(
  "ds/LineContainer.h",
  description: [Duy trì tập các đường thẳng dạng $y = k x + m$ và truy vấn giá trị *lớn nhất* tại điểm $x$. Nếu muốn tìm giá trị nhỏ nhất, đổi dấu `k`, `m` và kết quả truy vấn.
  ],
)
#file("ds/SWAD.h")
#file("ds/Mo.h")
#file("ds/WaveletTree.h")

= Đồ thị

// #file("graph/FordFulkerson.h", description: [
//   Tìm luồng cực đại bằng Ford-Fulkerson trong với $U$ là luồng tối đa trên một cạnh. Độ phức tạp $O(E F)$ với $F$ là luồng cực đại.
// ])
//
#file("graph/LowLink.h", description: [
  Tarjan tìm khớp cầu của đồ thị.
])
#file("graph/2CC.h", description: [
  Tìm thành phần song liên thông đỉnh (block-cut tree) và song liên thông cạnh (bridge tree).
])
#file("graph/SCC.h")
#file("graph/EulerWalk.h")
#file("graph/EnumTriangles.h", description: [
  Duyệt qua tất cả tam giác của đồ thị trong $O(M^(4/3))$
])
#file("graph/Dinic.h", description: [
  Tìm luồng cực đại. Nếu mọi cạnh đều có cap 1 thì độ phức tạp là $O(min(E^(2/3), V^(1/2)) E)$. Có cùng độ phức tạp với HopcroftKarp trong bài cặp ghép 2 phía nhưng chậm hơn 2 lần.
])
#file("graph/HopcroftKarp.h", description: [
  Cặp ghép cực đại trên đồ thị 2 phía trong $O(E sqrt(V))$. 0-indexed.
  Định lý Konig: Trong đồ thị 2 phía, MIS = N - cặp ghép cực đại.
])
#file("graph/GeneralMatching.h", description: [
  Tìm cặp ghép cực đại trên đồ thị thường trong $O(V^3)$. 0-indexed.
])
#file("graph/MinAssignment.h", description: [ Nhanh hơn Hungarian nhiều. Muốn tìm max cost, đặt cost âm. 0-indexed.])
#file("graph/CentroidDecomposition.h")
#file("graph/2SAT.h")
#file(
  "graph/Dominator.h",
  description: [Dựng Dominator Tree cho đồ thị có hướng khi đặt gốc là $s$. $u$ là cha của $v$ nếu mọi đường đi từ $s$ đến $v$ đều phải đi qua $u$. Độ phức tạp $O(M log N)$ hằng số thấp.
  ],
)
#file("graph/MinCostMaxFlow.h", description: [
  Min-cost max-flow. If costs can be negative, call `setpi` before `maxflow`, not support negative cycle. To obtain the actual flow, look at positive values only.

  *Time:* $O(F E log(V))$ where F is max flow. $O(V E)$ for `setpi`.
])
#file("graph/GlobalMinCut.h", description: [
  Tìm lát cắt cực tiểu trong đồ thị vô hướng trong $O(V^3)$.
])
#file(
  "graph/Cliques.h",
  description: [Duyệt clique hoặc tìm nhanh clique lớn nhất để giải MIS của phần bù trong $O(3^(n/3))$.],
)
// #file("graph/DirectedMST.h", description: [
//   Trả về giá trị và các cạnh của cây khung nhỏ nhất trên đồ thị có hướng với đỉnh nguồn cho trước trong $O(E log V)$. Nếu không tồn tại in ra `-1`.
// ])

= Xâu

1. Cho 2 xâu $S$, $T$. Số xâu phân biệt của prefix(S) + suffix(T) = $|S| * |T|$ - số kí tự giống nhau của S và T, không tính $S_0$ và $T_(n)$.

#file("strings/KMP.h", description: [])
#file("strings/Z.h")
#file("strings/MinRotation.h", description: [
  Min cyclic shift trong $O(n)$.
])
// #file("strings/Manacher.h")
#file("strings/AhoCorasick.h")
#file("strings/SuffixArray.h")
// #file("strings/PalindromeTree.h", description: [
//   Dựng Palindrome Tree. Nó có 2 root, root 0/1 cho xâu đối xứng chẵn/lẻ, mỗi node lưu độ dài xâu đối xứng, số lượng và link đến xâu đó. Xâu độ dài $N$ *chỉ có tối đa $N$ xâu con đối xứng phân biệt*.
// ])

= Quy hoạch động

== Bất đẳng thức tứ giác

Để áp dụng tối ưu hoá QHĐ, ta cần có:

$ w(i, j) + w(i+1, j+1) lt.eq w(i, j+1) + w(i+1, j) $

Ví dụ:

1. $w(i, j) = (j - i)^2$, $w(i, j) = (S[j] - S[i])^2$
2. $w(i, j) = |S[j] - S[i]|^P$
3. $w(i, j) = 1 / (j - i)$


#file("misc/CountSubseq.h")
#file(
  "misc/1D1D.h",
  description: [
    Tính hàm DP 1 chiều: $f(i) = min_(0 <= j < i) f(j) + w(j, i)$ trong $O(n log n)$.
  ],
  hash: false,
)
#file(
  "misc/Knuth.h",
  description: [Tính hàm DP: $f(i, j) = min_(i <= k < j) f(i, k) + f(k + 1, j) + w(j, i)$ trong $O(n^2)$.],
  hash: false,
)
#file(
  "misc/DnCDP.h",
  description: [Tính hàm DP: $f[i][j] = min_{k < j} (f[i-1][k] + w(k+1, j))$ trong $O(n log n)$.],
  hash: false,
)

= Khác

#file("misc/magics.h")
// #file("misc/debug.h")
#file("misc/maxHist.h")
#file("misc/Knight.h")

= Hình

Các thuật toán hình có đa giác, nếu không chú thích gì, thì hoạt động với mọi loại đa giác (lồi, lõm, tự cắt). Khi không còn bài gì để làm nữa thì hẵng làm hình.

#file("geometry/Point.h")
#file("geometry/TrianglePointCount.h")
#file("geometry/SideOf.h")
#file("geometry/ClosestPair.h")
#file(
  "geometry/ConvexHull.h",
  description: [Trả về bao lồi của tập điểm theo CCW. Nếu muốn tính cả điểm nằm trên biên, sửa `<=` thành `<`.],
)
#file("geometry/OnSegment.h")
#file("geometry/SegmentIntersection.h")
#file("geometry/LineDistance.h")
#file("geometry/LineIntersection.h")
#file("geometry/LineHullIntersection.h")
#file(
  "geometry/LineProjectionReflection.h",
  description: [Trả về chân đường vuông góc/điểm đối xứng (tuỳ vào `refl=false/true`) của điểm `p` qua đường `ab`. Các điểm phải là số thực, cẩn thận tràn số.],
)
#file("geometry/CircleLine.h")
#file("geometry/CircleIntersection.h")
#file("geometry/CircleTangents.h", description: [
  Tìm các tiếp tuyến ngoài của hai hình tròn, hoặc các tiếp tuyến trong nếu `r2` âm.

  - Có thể trả về `0`, `1` hoặc `2` tiếp tuyến:
  - `0` nếu một hình tròn chứa (hoặc chồng lên nhau, trong trường hợp nội tiếp, hoặc nếu hai hình tròn giống hệt nhau) hình tròn kia.
  - `1` nếu hai hình tròn tiếp xúc với nhau (trong trường hợp này `first` = `second` và đường tiếp tuyến vuông góc với đường nối giữa tâm).
  - `first` và `second` tương ứng cho biết các điểm tiếp xúc tại hình tròn 1 và hình tròn 2.
  - Để tìm các tiếp tuyến của một hình tròn với một điểm, hãy đặt `r2 = 0`.
])
#file("geometry/Circumcircle.h")
#file("geometry/MinimumEnclosingCircle.h")
#file(
  "geometry/CirclePolygonIntersection.h",
  description: [Trả về diện tích phần giao của đường tròn với đa giác trong $O(n)$],
)
#file("geometry/InsidePolygon.h")
#file("geometry/PolygonCenter.h")
#file("geometry/PolygonArea.h", description: [ Trả về 2 lần diện tích có dấu của đa giác.])
// #file(
//   "geometry/PolygonUnion.h",
//   description: [ Trả về diện tích giao nhau của $n$ đa giác trong $O(N^2)$ với $N$ là tổng số điểm. ],
// )
#file("geometry/PointInsideHull.h")
#file("geometry/HullDiameter.h")
// #file("geometry/Minkowski.h", description: [ Tính tổng của 2 bao lồi trong $O(n + m).$])
// #file(
//   "geometry/HalfplaneSet.h",
//   description: [Tìm bao lồi giao của nửa mặt phẳng trong $O(n log n)$. Nửa mặt phẳng được định nghĩa bằng $a x + b y <= c$],
// )

