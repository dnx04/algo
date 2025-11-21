#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "misc/macros.h"
#include "ds/DSURollback.h"

const int MAXN = 200005;
// Map index -1 về một chỉ số dương để dùng làm chỉ số mảng (ví dụ MAXN - 1)
const int ROOT_IDX = MAXN - 1;

struct QueryInfo {
  int t, k, u, v;
};

// adj[u]: Danh sách các truy vấn loại 0 (tạo đồ thị con) xuất phát từ trạng thái u
vector<int> adj[MAXN];

// checks[u]: Danh sách các truy vấn loại 1 (kiểm tra) cần thực hiện tại trạng thái u
vector<int> checks[MAXN];

QueryInfo qs[MAXN];
int ans[MAXN];     // Mảng lưu kết quả, khởi tạo -1
DSURollback* dsu;  // Con trỏ toàn cục để tiện dùng trong DFS

void dfs(int u) {
  // 1. Lưu kích thước lịch sử trước khi thay đổi
  int snapshot = dsu->his.size();

  // 2. Thực hiện thay đổi (nếu không phải gốc ảo)
  if (u != ROOT_IDX) {
    dsu->merge(qs[u].u, qs[u].v);
  }

  // 3. Trả lời các truy vấn kiểm tra tại trạng thái hiện tại
  for (int q_idx : checks[u]) {
    int root_u = dsu->root(qs[q_idx].u);
    int root_v = dsu->root(qs[q_idx].v);
    ans[q_idx] = (root_u == root_v ? 1 : 0);
  }

  // 4. Duyệt tiếp xuống các trạng thái con
  for (int v : adj[u]) {
    dfs(v);
  }

  // 5. Rollback (Hoàn tác) về trạng thái trước đó
  // Số lượng thao tác cần undo = kích thước hiện tại - kích thước lúc mới vào
  int ops_to_undo = dsu->his.size() - snapshot;
  dsu->undo(ops_to_undo);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  if (!(cin >> N >> Q)) return 0;

  dsu = new DSURollback(N);

  // Khởi tạo mảng kết quả
  for (int i = 0; i < Q; ++i) ans[i] = -1;

  for (int i = 0; i < Q; ++i) {
    cin >> qs[i].t >> qs[i].k >> qs[i].u >> qs[i].v;

    // Xử lý chỉ số k: nếu là -1 thì map về ROOT_IDX
    int parent = (qs[i].k == -1) ? ROOT_IDX : qs[i].k;

    if (qs[i].t == 0) {
      // Truy vấn loại 0: Tạo nút con trong cây phiên bản
      // i là chỉ số của truy vấn hiện tại, cũng là định danh cho trạng thái mới
      adj[parent].push_back(i);
    } else {
      // Truy vấn loại 1: Thêm vào danh sách kiểm tra của trạng thái cha
      checks[parent].push_back(i);
    }
  }

  // Bắt đầu DFS từ trạng thái rỗng
  dfs(ROOT_IDX);

  // In kết quả theo đúng thứ tự các truy vấn loại 1
  for (int i = 0; i < Q; ++i) {
    if (qs[i].t == 1) {
      cout << ans[i] << "\n";
    }
  }

  delete dsu;
  return 0;
}