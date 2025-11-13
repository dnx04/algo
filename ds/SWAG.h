struct AggStack {
  // Each element is stored as (value, current_min)
  stack<pair<int, int>> st;

  // Push a new number; compute the new min.
  void push(int x) {
    int cur = st.empty() ? x : min(st.top().second, x);
    st.push({x, cur});
  }

  // Pop the top element.
  void pop() { st.pop(); }

  // Return the current minimum.
  int agg() const { return st.top().second; }
};

struct AggQueue {
  AggStack in, out;

  // Push a new number into the queue.
  void push(int x) { in.push(x); }

  // Pop the oldest number.
  void pop() {
    if (out.st.empty()) {
      while (!in.st.empty()) {
        int v = in.st.top().first;
        in.pop();
        out.push(v);
      }
    }
    out.pop();
  }

  // Query the current minimum.
  int query() const {
    if (in.st.empty()) return out.agg();
    if (out.st.empty()) return in.agg();
    return min(in.agg(), out.agg());
  }
};