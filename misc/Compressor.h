template <typename T>
vi compressor(vector<T>& v) {
  auto cv = v;
  sort(all(cv));
  cv.erase(unique(all(cv)), cv.end());
  for (auto& e : v) e = lower_bound(all(cv), e) - cv.begin();
  return v;
}