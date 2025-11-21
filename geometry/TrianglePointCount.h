#include "Point.h"

template <class P, int MAXN, int MAXM>
struct TrianglePointCount {
  // Bảng lưu trạng thái: side[i][j] = bitset các điểm B nằm bên trái vector A[i]->A[j]
  bitset<MAXM> side[MAXN][MAXN];
  const vector<P>& A;  // Tham chiếu tới mảng A để kiểm tra hướng khi truy vấn
  // Constructor: Thực hiện Precomputation O(N^2 * M)
  TrianglePointCount(const vector<P>& A, const vector<P>& B)
      : A(A) {
    int n = sz(A), m = sz(B);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        P vecIJ = A[j] - A[i]; // Vector A[i] -> A[j]
        for (int k = 0; k < m; ++k) {
          P vecIK = B[k] - A[i]; // Vector A[i] -> B[k]
          // Nếu B[k] nằm thực sự bên trái A[i]->A[j] (cross product > 0)
          if (vecIJ.cross(vecIK) > 0) side[i][j][k] = 1;
        }
      }
    }
  }
  // Truy vấn: Đếm số điểm B nằm trong tam giác A[a], A[b], A[c]
  // Độ phức tạp: O(M/64) ~ O(1)
  int query(int a, int b, int c) {
    // Kiểm tra hướng của tam giác
    auto area = A[a].cross(A[b], A[c]);
    if (area == 0) return 0;  // Tam giác suy biến (thẳng hàng)
    if (area > 0) {
      // Ngược chiều kim đồng hồ (CCW): A->B->C
      // Điểm trong tam giác phải nằm trái AB, trái BC, VÀ trái CA
      return (side[a][b] & side[b][c] & side[c][a]).count();
    } else {
      // Cùng chiều kim đồng hồ (CW): A->C->B là CCW
      return (side[a][c] & side[c][b] & side[b][a]).count();
    }
  }
};