#import "@preview/codly:1.3.0": *
// #import "@preview/outrageous:0.3.0"
#import "@preview/cheq:0.3.0": checklist
#import "utils/icpc.typ": *

#set outline(indent: auto, depth: 4)

#show: codly-init.with()
// #show outline.entry: outrageous.show-entry.with()
#show: checklist

#codly(number-format: none)
#codly(display-icon: false)

#show: doc => icpc(
  team: [Quattuorvigintillion - University of Engineering and Technology, VNU],
  icon: "uet.png",
  doc,
)

#pagebreak()

= Thi cử

== Checklists

1. Wrong answer:
  - [ ] Clear data structure sau mỗi test case chưa ?
  - [ ] Thuật có đúng trong giới hạn input không ?
  - [ ] Đọc lại đề
  - [ ] Xét trường hợp biên chưa ?
  - [ ] Hiểu đúng đề chưa ?
  - [ ] Có biến nào chưa khởi tạo không ?
  - [ ] Tràn số ?
  - [ ] Nhầm biến (N với M, i với j) ?
  - [ ] Có chắc thuật đúng không ?
  - [ ] Có case nào không ngờ đến không ?
  - [ ] Nếu dùng STL, các hàm STL có hoạt động như ý muốn không ?
  - [ ] Debug bằng assert.
  - [ ] Trao đổi với teammate / 2 người cùng code.
  - [ ] Output format đúng chưa ?
  - [ ] Đọc lại checklist.

2. Runtime error:
  - [ ] Test trường hợp biên chưa ?
  - [ ] Biến chưa khởi tạo ?
  - [ ] Tràn mảng ?
  - [ ] Fail assert nào đó ?
  - [ ] Chia/mod cho 0 ?
  - [ ] Đệ quy vô hạn ?
  - [ ] Con trỏ hoặc iterator ?
  - [ ] Dùng quá nhiều bộ nhớ ?
  - [ ] Spam sub đề debug (e.g. remapped signals, see Various).

3. Time limit exceeded:
  - [ ] Lặp vô hạn ?
  - [ ] Độ phức tạp có đúng không ?
  - [ ] Tối ưu mod ?
  - [ ] Copy biến quá nhiều ?
  - [ ] Thay `vector, map` thành `array, unordered_map` ? Thay `int` thành `short` ?

4. Memory limit exceeded:
- [ ] Tối đa cần bao nhiêu bộ nhớ ?
- [ ] Clear data structure sau mỗi test case chưa ?

== Advices

- Khi không còn bài gì để làm thì hẵng làm hình.
- Nếu không sure bất cứ điều gì (kể cả đọc đề), hãy thảo luận với teammate.
- Viết pseudocode trước khi code, không chỉ để tiết kiệm computer time, mà còn tự phản biện chính mình.
- Đừng debug code trên máy. In code và debug output rồi debug trên giấy.
- Nếu kẹt, hãy đi dạo hoặc đi vệ sinh. Có thể nghĩ ra gì đó đấy.
- Nếu bị WA liên tục, để tạm đấy và xem bài khác rồi quay lại.
- Đừng ngại viết lại hết code, thường chỉ mất khoảng 15 phút.
- Nếu có thể dễ sinh ra input lớn hoặc tricky test, hãy cố làm điều đó trước khi nộp.
- Làm xong bài nào thì ném và xoá mọi thứ liên quan đến nó (đề bài, giấy nháp, ...).
- Ghi lại xem ai đang làm bài nào.
- Cuối giờ, mọi người tập trung vào 1 bài thôi.

#file("misc/commands.sh", hash: false)
#file("misc/macros.h", hash: false)
// #file("misc/c_cpp_properties.json")
// #file("misc/tasks.json")
// #file("misc/launch.json")

= Trick & Ghi chú

== Sequences

=== Catalan

$ C_n = 1 / (n + 1) binom(2n, n), C_(n + 1) = sum_(i=0)^n C_i C_(n - i) $

=== Lucas

Let $n = n_k p^k + n_(k-1) p^(k-1) + ... + n_0$ and $m = m_k p^k + m_(k-1) p^(k-1) + ... + m_0$ in base $p$. $ binom(n, m) = product_(i=0)^k binom(n_i, m_i) mod p $.

=== Number of Derangements

$d(n)$ là số hoán vị $n$ phần tử mà không có $i$ sao cho $p_i = i$. $ d(n) = (n - 1)(d(n - 1) + d(n - 2)) $.

=== Số Stirling loại 1

Số hoán vị $n$ phần tử có đúng $k$ chu trình.

$ s(n, k) = s(n - 1, k - 1) + (n - 1) s(n - 1, k) $

$ sum_(k = 0)^n s(n, k)x^k = x(x + 1)...(x + n - 1) $

=== Số Stirling loại 2

Số cách chia $n$ phần tử vào đúng $k$ nhóm.

$ S(n, k) = k S(n - 1, k) + S(n - 1, k - 1) $

$ S(n, k) = 1 / k! sum_(j = 0)^k (-1)^(k - j) binom(k, j) j^n $

== Bổ đề Burnside

Đặt $G$ là nhóm hữu hạn tác động lên tập $X$. Với mỗi $g in G$, gọi $X^g$ là tập các điểm bất định bởi g (${ x ∈ X | g.x = x }$). Số quỹ đạo có thể có là:

$ lr(|X/G|) = 1/lr(|G|) sum_(g in G) |X^g| $

== Super interpretation of kth powers

The square of the size of a set is equal to the number of ordered pairs of elements in the set. So we iterate over pairs and for each we compute the contribution to the answer.

Similarly, the $k$-th power is equal to the number of sequences (tuples) of length $k$.

$ E(X^2) = E(\#"ordered pairs"), E(X^k) = E(\#"ordered tuples") $

If you want to maintain the sum of $k$-th powers, it might help to also maintain the sum of smaller powers. For example, if the sum of $0$-th, $1$-th and $2$-nd powers is $S_0$, $S_1$ and $S_2$, and we increase all elements by $x$, the new sums are $S_0$, $S_1 + S_0 x$ and $S_2 + 2x S_1 + x^2 S_0$.

== Định lý Pick

Cho một đa giác có các điểm nguyên. Gọi $i$ là số điểm nguyên nằm trong đa giác, và $b$ là số điểm nguyên năm trên cạnh. Diện tích của đa giác là: $A = i + b/2 - 1$.

== Nhận xét

- Trong đồ thị 2 phía, MIS = N - cặp ghép cực đại.
- Cho 2 xâu $S$, $T$. Số xâu phân biệt của prefix(S) + suffix(T) = $|S| * |T|$ - số kí tự giống nhau của S và T, không tính $S_0$ và $T_(n)$.

= Toán

#file("math/MillerRabin.h", description: [
  Kiểm tra số nguyên tố nhanh, *chắc chắn* đúng trong `unsigned long long`.
])
#file("math/Matrix.h", description: [
  Ma trận vuông, hỗ trợ nhân và luỹ thừa.
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
  Duy trì hệ phương trình đồng dư.
])
#file("math/DivModSum.h", description: [
  Tính $sum_(i = 0)^(n - 1) (a + i times d) / m$ và $sum_(i = 0)^(n - 1) (a + i times d) mod m$. Độ phức tạp $O(log N)$
])
#file("math/FFT.h", description: [
  FFT trên $RR$
])
#file("math/NTT.h", description: [
  FFT modulo nguyên tố *bất kỳ* dựa trên FFT thực.
])
#file("math/FST.h", description: [
  Tính tích chập AND, OR, XOR.
])
#file("math/LinearRec.h", description: [
  Tìm số hạng thứ $k$ của dãy truy hồi cấp $n$ `S[i] = sum S[i-j-1]tr[j]` trong $O(n^2 log k)$.
])
#file("math/BerlekampMassey.h", description: [
  Phục hồi một dãy truy hồi cấp $n$ từ $2n$ số hạng đầu tiên trong $O(n^2)$.
])
#file("math/Lagrange.h", description: [
  Tìm đa thức bậc $n - 1$ qua $n$ điểm trong $O(n^2)$. Vẫn đúng trong trường modulo.
])
#file("math/RowEchelon.h", description: [
  Chuyển ma trận về dạng bậc thang trong $O(M^2 N)$, với $M$ là số hàng, $N$ là số cột.
])
#file("math/MatrixDet.h", description: [
  Tính định thức ma trận vuông trong $O(n^3)$.
])
#file("math/MatrixInv.h", description: [
  Tìm ma trận nghịch đảo trong $O(n^3)$.
])
#file("math/SolveLinear.h", description: [
  Giải hệ phương trình tuyến tính sau khi chuyển về dạng bậc thang trong $O(M^2 N)$.
])
#file("math/GaussBinary.h", description: [
  Giải hệ phương trình tuyến tính modulo 2 trong $O(n^3/64)$ sử dụng bitset.
])
#file("math/PolyRoots.h", description: [
  Tìm các nghiệm phức của đa thức bậc $n$ trong $O(n^2 times T)$ với $T$ là số lần lặp hội tụ. Nếu mò được nghiệm, hãy cho chúng vào phần khởi tạo.
])

= Cấu trúc dữ liệu

#file("ds/DSURollback.h")
#file("ds/RMQ.h")
#file("ds/HLD.h", description: [
  HLD cho phép truy vấn cả đường đi và cây con trong $O(log N)$.
  1. `pos(x)`: trả về vị trí của đỉnh `x` trong quá trình duyệt DFS.
  2. `subtree(x)`: trả về đoạn `[l, r)` tương ứng với cây con của `x`.
  3. `path_query(a, b, f)`: phân hoạch đường đi từ `a` đến `b` thành các đoạn liên tiếp trong mảng DFS. Hàm `f` có thể được dùng để truy vấn/cập nhật Segment Tree.
])
#file(
  "ds/LineContainer.h",
  description: [Duy trì tập các đường thẳng dạng $y = k x + m$ và truy vấn giá trị lớn nhất tại điểm $x$. Nếu muốn tìm giá trị nhỏ nhất, đổi dấu `k`, `m` và kết quả truy vấn.
  ],
)
#file("ds/SWAG.h")
#file("ds/PersistentIT.h")
#file("ds/WaveletTree.h")

= Đồ thị

#file("graph/FordFulkerson.h", description: [
  Tìm luồng cực đại bằng Ford-Fulkerson trong với $U$ là luồng tối đa trên một cạnh. Độ phức tạp $O(E F)$ với $F$ là luồng cực đại.
])
#file("graph/Dinic.h", description: [
  Tìm luồng cực đại bằng Dinic trong với $U$ là luồng tối đa trên một cạnh. Nếu mọi cạnh đều có luồng 1 thì độ phức tạp là $O(min(E^(2/3), V^(1/2)) E)$.

  Với bài cặp ghép 2 phía, độ phức tạp là $O(E sqrt(V))$.
])
#file("graph/HopcroftKarp.h", description: [
  Cặp ghép cực đại trên đồ thị 2 phía trong $O(E sqrt(V))$. 0-indexed.
  *Cách dùng:* `vi btoa(m, -1); hopcroftKarp(g, btoa);`
])
#file("graph/GeneralMatching.h", description: [
  Tìm cặp ghép cực đại trên đồ thị thường trong $O(V^3)$. 0-indexed.
])
#file("graph/MinAssignment.h", description: [ Nhanh hơn Hungarian nhiều. Muốn tìm max cost, đặt cost âm. 0-indexed.])
#file("graph/Biconnected.h", description: [
  Tìm tất cả thành phân song liên thông trong $O(E + V)$, và với mỗi thành phần chạy callback cho mỗi cạnh.
])
#file("graph/2SAT.h")
// #file("graph/EdgeColoring.h", description: [
//   Cho đồ thị $N$ đỉnh có bậc lớn nhất $D$, tô không quá $D + 1$ màu vào cạnh sao cho 2 cạnh kề nhau khác màu trong $O(N M)$.
// ])

#file(
  "graph/Dominator.h",
  description: [Dựng Dominator Tree cho đồ thị có hướng khi đặt gốc là $s$. $u$ là cha của $v$ nếu mọi đường đi từ $s$ đến $v$ đều phải đi qua $u$. Độ phức tạp $O(M log N)$ hằng số thấp.
  ],
)
#file("graph/GomoryHu.h", description: [
  Dựng cây Gomory-Hu của đồ thị luồng trong $N - 1$ lần chạy luồng. Max flow/min cut giữa 2 đỉnh $u, v$ trên đồ thị luồng là trọng số cạnh nhỏ nhất trên đường đi từ $u$ đến $v$.
])
#file("graph/MinCostMaxFlow.h", description: [
  Min-cost max-flow. If costs can be negative, call `setpi` before `maxflow`, not support negative cycle. To obtain the actual flow, look at positive values only.

  *Time:* $O(F E log(V))$ where F is max flow. $O(V E)$ for `setpi`.
])
#file("graph/GlobalMinCut.h", description: [
  Tìm lát cắt cực tiểu trong đồ thị vô hướng trong $O(V^3)$.
])
#file("graph/DirectedMST.h", description: [
  Trả về giá trị và các cạnh của cây khung nhỏ nhất trên đồ thị có hướng với đỉnh nguồn cho trước trong $O(E log V)$. Nếu không tồn tại in ra `-1`.
])

= Xâu

#file("strings/KMP.h", description: [])
#file("strings/Z.h")
#file("strings/MinRotation.h", description: [
  Tìm cyclic shift của xâu có thứ tự từ điển nhỏ nhất trong $O(n)$.
])
// #file("strings/Manacher.h")
// #file("strings/AhoCorasick.h")
// #file("strings/SuffixArray.h", description: [Suffix Array và LCP trong $O(n log n)$.])
#file("strings/PalindromeTree.h", description: [
  Dựng Palindrome Tree. Nó có 2 root, root 0/1 cho xâu đối xứng chẵn/lẻ, mỗi node lưu độ dài xâu đối xứng, số lượng và link đến xâu đó. Xâu độ dài $N$ *chỉ có tối đa $N$ xâu con đối xứng phân biệt*.
])

= Khác

#file("misc/maxHist.h", description: [
  Hình chữ nhật lớn nhất.
])
#file("misc/FracBinarySearch.h", description: [
  Tìm phân số $p/q$ nhỏ nhất trong đoạn $[0, 1]$ sao cho $f(p/q)$ là đúng, với $p <= m_p, q <= m_q$
])
#file("misc/ContinuedFraction.h", description: [
  Cho $N$ và số thực $x > 0$, tính xấp xỉ hữu tỉ $p/q$ của $x$ với $p, q <= N$ trong $O(log N)$. Đảm bảo $abs(p/q - x) < 1/q$.

])
#file(
  "misc/1D1D.cpp",
  description: [
    Nếu hàm $w(i, j)$ thoả mãn bất đẳng thức tứ giác: $w(a, c) + w(b, d) <= w(a, d) + w(b, c)$ với mọi $a < b < c < d$, thì ta có thể tính hàm DP 1 chiều: $f(i) = min_(0 <= j < i) f(j) + w(j, i)$ trong $O(n log n)$.
  ],
  hash: false,
)
#file(
  "misc/SOSDP.cpp",
  description: [
    Toàn bộ implementation SOS DP của VNOI.
  ],
  hash: false,
)
#file(
  "misc/Knuth.h",
  description: [Nếu hàm $w(i, j)$ thoả mãn bất đẳng thức tứ giác: $w(a, c) + w(b, d) <= w(a, d) + w(b, c)$ với mọi $a < b < c < d$, thì ta có thể tính hàm DP: $f(i, j) = min_(i <= k < j) f(i, k) + f(k + 1, j) + w(j, i)$ trong $O(n^2)$.],
  hash: false,
)
#file("misc/HexGrid.h", hash: false)
#file(
  "misc/MaximalCliques.h",
  description: [Chạy một hàm nào đó duyệt qua tất cả các clique của một đồ thị trong $O(3^(n/3))$.],
)
#file(
  "misc/MaximumClique.h",
  description: [Tìm nhanh một clique lớn nhất. Dùng để giải Maximum Independent Set bằng cách tính maximum clique của phần bù.],
)
#file(
  "misc/Frievalds.cpp",
  description: [Kiểm tra xác suất tích ma trận $A B = C$ trong $O(T n^2)$. Xác suất sai là $2^(-T)$.],
)
#file("misc/XorBasis.h")

= Hình

Các thuật toán hình có đa giác, nếu không chú thích gì, thì hoạt động với mọi loại đa giác (lồi, lõm, tự cắt). Khi không còn bài gì để làm nữa thì hẵng làm hình.

#file("geometry/Point.h")
#file("geometry/SideOf.h")
#file("geometry/ClosestPair.h")
#file(
  "geometry/ConvexHull.h",
  description: [Trả về bao lồi của tập điểm theo CCW. Nếu muốn tính cả điểm nằm trên biên, sửa `<=` thành `<`.],
)

#file("geometry/OnSegment.h")
#file("geometry/LineDistance.h")
#file("geometry/LineIntersection.h")
#file(
  "geometry/LineProjectionReflection.h",
  description: [Trả về chân đường vuông góc/điểm đối xứng (tuỳ vào `refl=false/true`) của điểm `p` qua đường `ab`. Các điểm phải là số thực, cẩn thận tràn số.],
)

#file("geometry/CircleLine.h", description: [Định nghĩa của đường thẳng dạng $a x + b y = c$ với $a, b, c in ZZ/RR$])
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
#file(
  "geometry/PolygonUnion.h",
  description: [ Trả về diện tích giao nhau của $n$ đa giác trong $O(N^2)$ với $N$ là tổng số điểm. ],
)

#file("geometry/PointInsideHull.h")
#file("geometry/HullDiameter.h")
#file("geometry/Minkowski.h", description: [ Tính tổng của 2 bao lồi trong $O(n + m).$])
#file("geometry/Line.h", description: [Định nghĩa của đường thẳng dạng $y = k x + m$ với $k, m in ZZ$ hoặc $RR$])
// #file(
//   "geometry/HalfplaneSet.h",
//   description: [Tìm bao lồi giao của nửa mặt phẳng trong $O(n log n)$. Nửa mặt phẳng được định nghĩa bằng $a x + b y <= c$],
)

