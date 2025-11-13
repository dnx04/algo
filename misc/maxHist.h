int maxHist(vector<int>& h) {
  h.push_back(0);
  stack<int> st;
  int res = 0;
  for (int i = 0; i < (int)h.size(); i++) {
    while (!st.empty() && h[st.top()] >= h[i]) {
      int height = h[st.top()];
      st.pop();
      int width = st.empty() ? i : i - st.top() - 1;
      res = max(res, height * width);
    }
    st.push(i);
  }
  return res;
}
