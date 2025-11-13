struct item {
  int l, r, p;
};

const int N = 1e5 + 3;
int n;
long long f[N];

long long w(int j, int i) {
  // một hàm cost bất kì thỏa mãn bất đẳng thức tứ giác
}

void solve() {
  deque<item> dq;
  dq.push_back({1, n, 0});
  for (int i = 1; i <= n; ++i) {
    f[i] = f[dq.front().p] + w(dq.front().p, i);
    // deque chỉ lưu giá trị từ h[i + 1]
    // tới h[n]
    ++dq.front().l;

    // nếu l > r, ta loại đoạn này khỏi deque
    if (dq.front().l > dq.front().r) {
      dq.pop_front();
    }

    while (!dq.empty()) {
      auto [l, r, p] = dq.back();
      if (f[i] + w(i, l) < f[p] + w(p, l)) {
        dq.pop_back();
        // p không còn là giá trị của
        // h[l], h[l + 1], ..., h[r]
        // lúc này, h[l]=h[l+1]=...=h[r]=i.
      } else
        break;
    }

    if (dq.empty()) {
      dq.push_back({i + 1, n, i});
      // h[i+1]=h[i+2]=...=h[n]=i
    } else {
      // tìm nhị phân vị trí pos nhỏ nhất
      // thỏa mãn h[pos] = i
      auto& [l, r, p] = dq.back();
      int low = l, high = r;
      int pos = r + 1, mid;
      while (low <= high) {
        mid = (low + high) / 2;
        if (f[i] + w(i, mid) < f[p] + w(p, mid)) {
          pos = mid, high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      // cập nhật đoạn (l,r,p) thành (l,pos-1,p)
      r = pos - 1;
      if (pos <= n) {
        dq.push_back({pos, n, i});
        // h[pos]=h[pos+1]=...=h[n]=i
      }
    }
  }
}