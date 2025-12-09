#ifdef LOCAL
  int dbLvl = 0;
  #define db(x...) cerr << string(dbLvl*2,' ') << "L" << __LINE__ << " [" << #x << "] = ["; debug(x)
  #define DB() Scope _scope_(__LINE__)
  struct Scope {
      Scope(int l) { cerr << string(dbLvl*2,' ') << "L" << l << " {\n"; dbLvl++; }
      ~Scope() { dbLvl--; cerr << string(dbLvl*2,' ') << "}\n"; }
  };
#else
    #define db(...)
    #define DB()
#endif

// 1. In Pair
template<class T, class V> ostream& operator<<(ostream& os, pair<T, V> p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
// 2. In Struct có hàm .debug(os)
template<class T> auto operator<<(ostream& os, const T& t) -> decltype(t.debug(os), os) {
    t.debug(os); return os;
}
// 3. In Container
template<class T, typename = enable_if_t<!is_same_v<decay_t<T>, string>>>
auto operator<<(ostream& os, T v) -> decltype(v.end(), os) {
    os << "{"; int i=0; for(auto e:v) os << (i++?", ":"") << e; return os << "}";
}
// 4. In tuple
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
    os << "("; apply([&os](auto&&... args){ int n=0; ((os << (n++?", ":"") << args), ...); }, t); return os << ")";
}
// 5. In debug (bao nhiêu biến cũng được)
void debug() { cerr << "]\n"; }
template<class T, class... V> void debug(T t, V... v) {
    cerr << t; if (sizeof...(v)) cerr << ", "; debug(v...);
}