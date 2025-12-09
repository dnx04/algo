---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/debug.h\"\n#ifdef LOCAL\n  int dbLvl = 0;\n  #define\
    \ db(x...) cerr << string(dbLvl*2,' ') << \"L\" << __LINE__ << \" [\" << #x <<\
    \ \"] = [\"; debug(x)\n  #define DB() Scope _scope_(__LINE__)\n  struct Scope\
    \ {\n      Scope(int l) { cerr << string(dbLvl*2,' ') << \"L\" << l << \" {\\\
    n\"; dbLvl++; }\n      ~Scope() { dbLvl--; cerr << string(dbLvl*2,' ') << \"}\\\
    n\"; }\n  };\n#else\n    #define db(...)\n    #define DB()\n#endif\n\n// 1. In\
    \ Pair\ntemplate<class T, class V> ostream& operator<<(ostream& os, pair<T, V>\
    \ p) {\n    return os << \"(\" << p.first << \", \" << p.second << \")\";\n}\n\
    // 2. In Struct c\xF3 h\xE0m .debug(os)\ntemplate<class T> auto operator<<(ostream&\
    \ os, const T& t) -> decltype(t.debug(os), os) {\n    t.debug(os); return os;\n\
    }\n// 3. In Container\ntemplate<class T, typename = enable_if_t<!is_same_v<decay_t<T>,\
    \ string>>>\nauto operator<<(ostream& os, T v) -> decltype(v.end(), os) {\n  \
    \  os << \"{\"; int i=0; for(auto e:v) os << (i++?\", \":\"\") << e; return os\
    \ << \"}\";\n}\n// 4. In tuple\ntemplate<class... T> ostream& operator<<(ostream&\
    \ os, const tuple<T...>& t) {\n    os << \"(\"; apply([&os](auto&&... args){ int\
    \ n=0; ((os << (n++?\", \":\"\") << args), ...); }, t); return os << \")\";\n\
    }\n// 5. In debug (bao nhi\xEAu bi\u1EBFn c\u0169ng \u0111\u01B0\u1EE3c)\nvoid\
    \ debug() { cerr << \"]\\n\"; }\ntemplate<class T, class... V> void debug(T t,\
    \ V... v) {\n    cerr << t; if (sizeof...(v)) cerr << \", \"; debug(v...);\n}\n"
  code: "#ifdef LOCAL\n  int dbLvl = 0;\n  #define db(x...) cerr << string(dbLvl*2,'\
    \ ') << \"L\" << __LINE__ << \" [\" << #x << \"] = [\"; debug(x)\n  #define DB()\
    \ Scope _scope_(__LINE__)\n  struct Scope {\n      Scope(int l) { cerr << string(dbLvl*2,'\
    \ ') << \"L\" << l << \" {\\n\"; dbLvl++; }\n      ~Scope() { dbLvl--; cerr <<\
    \ string(dbLvl*2,' ') << \"}\\n\"; }\n  };\n#else\n    #define db(...)\n    #define\
    \ DB()\n#endif\n\n// 1. In Pair\ntemplate<class T, class V> ostream& operator<<(ostream&\
    \ os, pair<T, V> p) {\n    return os << \"(\" << p.first << \", \" << p.second\
    \ << \")\";\n}\n// 2. In Struct c\xF3 h\xE0m .debug(os)\ntemplate<class T> auto\
    \ operator<<(ostream& os, const T& t) -> decltype(t.debug(os), os) {\n    t.debug(os);\
    \ return os;\n}\n// 3. In Container\ntemplate<class T, typename = enable_if_t<!is_same_v<decay_t<T>,\
    \ string>>>\nauto operator<<(ostream& os, T v) -> decltype(v.end(), os) {\n  \
    \  os << \"{\"; int i=0; for(auto e:v) os << (i++?\", \":\"\") << e; return os\
    \ << \"}\";\n}\n// 4. In tuple\ntemplate<class... T> ostream& operator<<(ostream&\
    \ os, const tuple<T...>& t) {\n    os << \"(\"; apply([&os](auto&&... args){ int\
    \ n=0; ((os << (n++?\", \":\"\") << args), ...); }, t); return os << \")\";\n\
    }\n// 5. In debug (bao nhi\xEAu bi\u1EBFn c\u0169ng \u0111\u01B0\u1EE3c)\nvoid\
    \ debug() { cerr << \"]\\n\"; }\ntemplate<class T, class... V> void debug(T t,\
    \ V... v) {\n    cerr << t; if (sizeof...(v)) cerr << \", \"; debug(v...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/debug.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/debug.h
layout: document
redirect_from:
- /library/misc/debug.h
- /library/misc/debug.h.html
title: misc/debug.h
---
