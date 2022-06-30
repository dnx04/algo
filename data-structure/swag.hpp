template <class T, class Op>
struct SWAG {
  T e;
  Op op;
  deque<T> dq;
  int front;
  T back;

  SWAG(T e_, Op op_) : e(e_), op(op_) {
    front = 0;
    back = e;
  }

  void push(T x) {
    dq.push_back(x);
    back = op(back, x);
  }

  void pop() {
    assert(not dq.empty());
    dq.pop_front();
    if (front) {
      --front;
    } else {
      int len = dq.size();
      for (int i = len - 2; i >= 0; i--) dq[i] = op(dq[i], dq[i + 1]);
      front = len;
      back = e;
    }
  }

  T sum() const { return front ? op(dq.front(), back) : back; }
};