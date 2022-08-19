---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path.hpp\"\ntemplate <typename T, T INF =\
    \ numeric_limits<T>::max() / 2,\n          int INVALID = -1>\nstruct shortest_path\
    \ {\n  int V, E;\n  bool single_positive_weight;\n  T wmin, wmax;\n\n  vector<pair<int,\
    \ T>> tos;\n  vector<int> head;\n  vector<tuple<int, int, T>> edges;\n\n  void\
    \ build() {\n    if (int(tos.size()) == E and int(head.size()) == V + 1) return;\n\
    \    tos.resize(E);\n    head.assign(V + 1, 0);\n    for (const auto &e : edges)\
    \ ++head[get<0>(e) + 1];\n    for (int i = 0; i < V; ++i) head[i + 1] += head[i];\n\
    \    auto cur = head;\n    for (const auto &e : edges) {\n      tos[cur[get<0>(e)]++]\
    \ =\n          make_pair(get<1>(e), get<2>(e));\n    }\n  }\n\n  shortest_path(int\
    \ V = 0)\n      : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0) {}\n\
    \  void add_edge(int s, int t, T w) {\n    assert(0 <= s and s < V);\n    assert(0\
    \ <= t and t < V);\n    edges.emplace_back(s, t, w);\n    ++E;\n    if (w > 0\
    \ and wmax > 0 and wmax != w) single_positive_weight = false;\n    wmin = min(wmin,\
    \ w);\n    wmax = max(wmax, w);\n  }\n\n  void add_bi_edge(int u, int v, T w)\
    \ {\n    add_edge(u, v, w);\n    add_edge(v, u, w);\n  }\n\n  vector<T> dist;\n\
    \  vector<int> prev;\n\n  // Dijkstra algorithm\n  // - Requirement: wmin >= 0\n\
    \  // - Complexity: O(E log E)\n  using Pque =\n      priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>,\n                          greater<pair<T, int>>>;\n \
    \ template <class Heap = Pque>\n  void dijkstra(int s, int t = INVALID) {\n  \
    \  assert(0 <= s and s < V);\n    build();\n    dist.assign(V, INF);\n    prev.assign(V,\
    \ INVALID);\n    dist[s] = 0;\n    Heap pq;\n    pq.emplace(0, s);\n    while\
    \ (!pq.empty()) {\n      T d;\n      int v;\n      tie(d, v) = pq.top();\n   \
    \   pq.pop();\n      if (t == v) return;\n      if (dist[v] < d) continue;\n \
    \     for (int e = head[v]; e < head[v + 1]; ++e) {\n        const auto &nx =\
    \ tos[e];\n        T dnx = d + nx.second;\n        if (dist[nx.first] > dnx) {\n\
    \          dist[nx.first] = dnx, prev[nx.first] = v;\n          pq.emplace(dnx,\
    \ nx.first);\n        }\n      }\n    }\n  }\n\n  // Dijkstra algorithm\n  //\
    \ - Requirement: wmin >= 0\n  // - Complexity: O(V^2 + E)\n  void dijkstra_vquad(int\
    \ s, int t = INVALID) {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V,\
    \ INF);\n    prev.assign(V, INVALID);\n    dist[s] = 0;\n    vector<char> fixed(V,\
    \ false);\n    while (true) {\n      int r = INVALID;\n      T dr = INF;\n   \
    \   for (int i = 0; i < V; i++) {\n        if (!fixed[i] and dist[i] < dr) r =\
    \ i, dr = dist[i];\n      }\n      if (r == INVALID or r == t) break;\n      fixed[r]\
    \ = true;\n      int nxt;\n      T dx;\n      for (int e = head[r]; e < head[r\
    \ + 1]; ++e) {\n        tie(nxt, dx) = tos[e];\n        if (dist[nxt] > dist[r]\
    \ + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;\n      }\n    }\n  }\n\n  //\
    \ Bellman-Ford algorithm\n  // - Requirement: no negative loop\n  // - Complexity:\
    \ O(VE)\n  bool bellman_ford(int s, int nb_loop) {\n    assert(0 <= s and s <\
    \ V);\n    build();\n    dist.assign(V, INF), prev.assign(V, INVALID);\n    dist[s]\
    \ = 0;\n    for (int l = 0; l < nb_loop; l++) {\n      bool upd = false;\n   \
    \   for (int v = 0; v < V; v++) {\n        if (dist[v] == INF) continue;\n   \
    \     for (int e = head[v]; e < head[v + 1]; ++e) {\n          const auto &nx\
    \ = tos[e];\n          T dnx = dist[v] + nx.second;\n          if (dist[nx.first]\
    \ > dnx)\n            dist[nx.first] = dnx, prev[nx.first] = v, upd = true;\n\
    \        }\n      }\n      if (!upd) return true;\n    }\n    return false;\n\
    \  }\n\n  // Bellman-ford algorithm using deque\n  // - Requirement: no negative\
    \ loop\n  // - Complexity: O(VE)\n  void spfa(int s) {\n    assert(0 <= s and\
    \ s < V);\n    build();\n    dist.assign(V, INF);\n    prev.assign(V, INVALID);\n\
    \    dist[s] = 0;\n    deque<int> q;\n    vector<char> in_queue(V);\n    q.push_back(s),\
    \ in_queue[s] = 1;\n    while (!q.empty()) {\n      int now = q.front();\n   \
    \   q.pop_front(), in_queue[now] = 0;\n      for (int e = head[now]; e < head[now\
    \ + 1]; ++e) {\n        const auto &nx = tos[e];\n        T dnx = dist[now] +\
    \ nx.second;\n        int nxt = nx.first;\n        if (dist[nxt] > dnx) {\n  \
    \        dist[nxt] = dnx;\n          if (!in_queue[nxt]) {\n            if (q.size()\
    \ and\n                dnx < dist[q.front()]) {  // Small label first optimization\n\
    \              q.push_front(nxt);\n            } else {\n              q.push_back(nxt);\n\
    \            }\n            prev[nxt] = now, in_queue[nxt] = 1;\n          }\n\
    \        }\n      }\n    }\n  }\n\n  // 01-BFS\n  // - Requirement: all weights\
    \ must be 0 or w (positive constant).\n  // - Complexity: O(V + E)\n  void zero_one_bfs(int\
    \ s, int t = INVALID) {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V,\
    \ INF), prev.assign(V, INVALID);\n    dist[s] = 0;\n    vector<int> q(V * 4);\n\
    \    int ql = V * 2, qr = V * 2;\n    q[qr++] = s;\n    while (ql < qr) {\n  \
    \    int v = q[ql++];\n      if (v == t) return;\n      for (int e = head[v];\
    \ e < head[v + 1]; ++e) {\n        const auto &nx = tos[e];\n        T dnx = dist[v]\
    \ + nx.second;\n        if (dist[nx.first] > dnx) {\n          dist[nx.first]\
    \ = dnx, prev[nx.first] = v;\n          if (nx.second) {\n            q[qr++]\
    \ = nx.first;\n          } else {\n            q[--ql] = nx.first;\n         \
    \ }\n        }\n      }\n    }\n  }\n\n  // Dial's algorithm\n  // - Requirement:\
    \ wmin >= 0\n  // - Complexity: O(wmax * V + E)\n  void dial(int s, int t = INVALID)\
    \ {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V, INF), prev.assign(V,\
    \ INVALID);\n    dist[s] = 0;\n    vector<vector<pair<int, T>>> q(wmax + 1);\n\
    \    q[0].emplace_back(s, dist[s]);\n    int ninq = 1;\n\n    int cur = 0;\n \
    \   T dcur = 0;\n    for (; ninq; ++cur, ++dcur) {\n      if (cur == wmax + 1)\
    \ cur = 0;\n      while (!q[cur].empty()) {\n        int v = q[cur].back().first;\n\
    \        T dnow = q[cur].back().second;\n        q[cur].pop_back(), --ninq;\n\
    \        if (v == t) return;\n        if (dist[v] < dnow) continue;\n\n      \
    \  for (int e = head[v]; e < head[v + 1]; ++e) {\n          const auto &nx = tos[e];\n\
    \          T dnx = dist[v] + nx.second;\n          if (dist[nx.first] > dnx) {\n\
    \            dist[nx.first] = dnx, prev[nx.first] = v;\n            int nxtcur\
    \ = cur + int(nx.second);\n            if (nxtcur >= int(q.size())) nxtcur -=\
    \ q.size();\n            q[nxtcur].emplace_back(nx.first, dnx), ++ninq;\n    \
    \      }\n        }\n      }\n    }\n  }\n\n  // Solver for DAG\n  // - Requirement:\
    \ graph is DAG\n  // - Complexity: O(V + E)\n  bool dag_solver(int s) {\n    assert(0\
    \ <= s and s < V);\n    build();\n    dist.assign(V, INF), prev.assign(V, INVALID);\n\
    \    dist[s] = 0;\n    vector<int> indeg(V, 0);\n    vector<int> q(V * 2);\n \
    \   int ql = 0, qr = 0;\n    q[qr++] = s;\n    while (ql < qr) {\n      int now\
    \ = q[ql++];\n      for (int e = head[now]; e < head[now + 1]; ++e) {\n      \
    \  const auto &nx = tos[e];\n        ++indeg[nx.first];\n        if (indeg[nx.first]\
    \ == 1) q[qr++] = nx.first;\n      }\n    }\n    ql = qr = 0;\n    q[qr++] = s;\n\
    \    while (ql < qr) {\n      int now = q[ql++];\n      for (int e = head[now];\
    \ e < head[now + 1]; ++e) {\n        const auto &nx = tos[e];\n        --indeg[nx.first];\n\
    \        if (dist[nx.first] > dist[now] + nx.second)\n          dist[nx.first]\
    \ = dist[now] + nx.second, prev[nx.first] = now;\n        if (indeg[nx.first]\
    \ == 0) q[qr++] = nx.first;\n      }\n    }\n    return *max_element(indeg.begin(),\
    \ indeg.end()) == 0;\n  }\n\n  // Retrieve a sequence of vertex ids that represents\
    \ shortest path [s, ...,\n  // goal] If not reachable to goal, return {}\n  vector<int>\
    \ retrieve_path(int goal) const {\n    assert(int(prev.size()) == V);\n    assert(0\
    \ <= goal and goal < V);\n    if (dist[goal] == INF) return {};\n    vector<int>\
    \ ret{goal};\n    while (prev[goal] != INVALID) {\n      goal = prev[goal];\n\
    \      ret.push_back(goal);\n    }\n    reverse(ret.begin(), ret.end());\n   \
    \ return ret;\n  }\n\n  void solve(int s, int t = INVALID) {\n    if (wmin >=\
    \ 0) {\n      if (single_positive_weight) {\n        zero_one_bfs(s, t);\n   \
    \   } else if (wmax <= 10) {\n        dial(s, t);\n      } else {\n        if\
    \ ((long long)V * V < (E << 4)) {\n          dijkstra_vquad(s, t);\n        }\
    \ else {\n          dijkstra(s, t);\n        }\n      }\n    } else {\n      bellman_ford(s,\
    \ V);\n    }\n  }\n\n  // Warshall-Floyd algorithm\n  // - Requirement: no negative\
    \ loop\n  // - Complexity: O(E + V^3)\n  vector<vector<T>> floyd_warshall() {\n\
    \    build();\n    vector<vector<T>> dist2d(V, vector<T>(V, INF));\n    for (int\
    \ i = 0; i < V; i++) {\n      dist2d[i][i] = 0;\n      for (const auto &e : edges)\
    \ {\n        int s = get<0>(e), t = get<1>(e);\n        dist2d[s][t] = min(dist2d[s][t],\
    \ get<2>(e));\n      }\n    }\n    for (int k = 0; k < V; k++) {\n      for (int\
    \ i = 0; i < V; i++) {\n        if (dist2d[i][k] == INF) continue;\n        for\
    \ (int j = 0; j < V; j++) {\n          if (dist2d[k][j] == INF) continue;\n  \
    \        dist2d[i][j] = min(dist2d[i][j], dist2d[i][k] + dist2d[k][j]);\n    \
    \    }\n      }\n    }\n    return dist2d;\n  }\n\n  void to_dot(string filename\
    \ = \"shortest_path\") const {\n    ofstream ss(filename + \".DOT\");\n    ss\
    \ << \"digraph{\\n\";\n    build();\n    for (int i = 0; i < V; i++) {\n     \
    \ for (int e = head[i]; e < head[i + 1]; ++e) {\n        ss << i << \"->\" <<\
    \ tos[e].first << \"[label=\" << tos[e].second << \"];\\n\";\n      }\n    }\n\
    \    ss << \"}\\n\";\n    ss.close();\n    return;\n  }\n};\n"
  code: "template <typename T, T INF = numeric_limits<T>::max() / 2,\n          int\
    \ INVALID = -1>\nstruct shortest_path {\n  int V, E;\n  bool single_positive_weight;\n\
    \  T wmin, wmax;\n\n  vector<pair<int, T>> tos;\n  vector<int> head;\n  vector<tuple<int,\
    \ int, T>> edges;\n\n  void build() {\n    if (int(tos.size()) == E and int(head.size())\
    \ == V + 1) return;\n    tos.resize(E);\n    head.assign(V + 1, 0);\n    for (const\
    \ auto &e : edges) ++head[get<0>(e) + 1];\n    for (int i = 0; i < V; ++i) head[i\
    \ + 1] += head[i];\n    auto cur = head;\n    for (const auto &e : edges) {\n\
    \      tos[cur[get<0>(e)]++] =\n          make_pair(get<1>(e), get<2>(e));\n \
    \   }\n  }\n\n  shortest_path(int V = 0)\n      : V(V), E(0), single_positive_weight(true),\
    \ wmin(0), wmax(0) {}\n  void add_edge(int s, int t, T w) {\n    assert(0 <= s\
    \ and s < V);\n    assert(0 <= t and t < V);\n    edges.emplace_back(s, t, w);\n\
    \    ++E;\n    if (w > 0 and wmax > 0 and wmax != w) single_positive_weight =\
    \ false;\n    wmin = min(wmin, w);\n    wmax = max(wmax, w);\n  }\n\n  void add_bi_edge(int\
    \ u, int v, T w) {\n    add_edge(u, v, w);\n    add_edge(v, u, w);\n  }\n\n  vector<T>\
    \ dist;\n  vector<int> prev;\n\n  // Dijkstra algorithm\n  // - Requirement: wmin\
    \ >= 0\n  // - Complexity: O(E log E)\n  using Pque =\n      priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>,\n                          greater<pair<T, int>>>;\n\
    \  template <class Heap = Pque>\n  void dijkstra(int s, int t = INVALID) {\n \
    \   assert(0 <= s and s < V);\n    build();\n    dist.assign(V, INF);\n    prev.assign(V,\
    \ INVALID);\n    dist[s] = 0;\n    Heap pq;\n    pq.emplace(0, s);\n    while\
    \ (!pq.empty()) {\n      T d;\n      int v;\n      tie(d, v) = pq.top();\n   \
    \   pq.pop();\n      if (t == v) return;\n      if (dist[v] < d) continue;\n \
    \     for (int e = head[v]; e < head[v + 1]; ++e) {\n        const auto &nx =\
    \ tos[e];\n        T dnx = d + nx.second;\n        if (dist[nx.first] > dnx) {\n\
    \          dist[nx.first] = dnx, prev[nx.first] = v;\n          pq.emplace(dnx,\
    \ nx.first);\n        }\n      }\n    }\n  }\n\n  // Dijkstra algorithm\n  //\
    \ - Requirement: wmin >= 0\n  // - Complexity: O(V^2 + E)\n  void dijkstra_vquad(int\
    \ s, int t = INVALID) {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V,\
    \ INF);\n    prev.assign(V, INVALID);\n    dist[s] = 0;\n    vector<char> fixed(V,\
    \ false);\n    while (true) {\n      int r = INVALID;\n      T dr = INF;\n   \
    \   for (int i = 0; i < V; i++) {\n        if (!fixed[i] and dist[i] < dr) r =\
    \ i, dr = dist[i];\n      }\n      if (r == INVALID or r == t) break;\n      fixed[r]\
    \ = true;\n      int nxt;\n      T dx;\n      for (int e = head[r]; e < head[r\
    \ + 1]; ++e) {\n        tie(nxt, dx) = tos[e];\n        if (dist[nxt] > dist[r]\
    \ + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;\n      }\n    }\n  }\n\n  //\
    \ Bellman-Ford algorithm\n  // - Requirement: no negative loop\n  // - Complexity:\
    \ O(VE)\n  bool bellman_ford(int s, int nb_loop) {\n    assert(0 <= s and s <\
    \ V);\n    build();\n    dist.assign(V, INF), prev.assign(V, INVALID);\n    dist[s]\
    \ = 0;\n    for (int l = 0; l < nb_loop; l++) {\n      bool upd = false;\n   \
    \   for (int v = 0; v < V; v++) {\n        if (dist[v] == INF) continue;\n   \
    \     for (int e = head[v]; e < head[v + 1]; ++e) {\n          const auto &nx\
    \ = tos[e];\n          T dnx = dist[v] + nx.second;\n          if (dist[nx.first]\
    \ > dnx)\n            dist[nx.first] = dnx, prev[nx.first] = v, upd = true;\n\
    \        }\n      }\n      if (!upd) return true;\n    }\n    return false;\n\
    \  }\n\n  // Bellman-ford algorithm using deque\n  // - Requirement: no negative\
    \ loop\n  // - Complexity: O(VE)\n  void spfa(int s) {\n    assert(0 <= s and\
    \ s < V);\n    build();\n    dist.assign(V, INF);\n    prev.assign(V, INVALID);\n\
    \    dist[s] = 0;\n    deque<int> q;\n    vector<char> in_queue(V);\n    q.push_back(s),\
    \ in_queue[s] = 1;\n    while (!q.empty()) {\n      int now = q.front();\n   \
    \   q.pop_front(), in_queue[now] = 0;\n      for (int e = head[now]; e < head[now\
    \ + 1]; ++e) {\n        const auto &nx = tos[e];\n        T dnx = dist[now] +\
    \ nx.second;\n        int nxt = nx.first;\n        if (dist[nxt] > dnx) {\n  \
    \        dist[nxt] = dnx;\n          if (!in_queue[nxt]) {\n            if (q.size()\
    \ and\n                dnx < dist[q.front()]) {  // Small label first optimization\n\
    \              q.push_front(nxt);\n            } else {\n              q.push_back(nxt);\n\
    \            }\n            prev[nxt] = now, in_queue[nxt] = 1;\n          }\n\
    \        }\n      }\n    }\n  }\n\n  // 01-BFS\n  // - Requirement: all weights\
    \ must be 0 or w (positive constant).\n  // - Complexity: O(V + E)\n  void zero_one_bfs(int\
    \ s, int t = INVALID) {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V,\
    \ INF), prev.assign(V, INVALID);\n    dist[s] = 0;\n    vector<int> q(V * 4);\n\
    \    int ql = V * 2, qr = V * 2;\n    q[qr++] = s;\n    while (ql < qr) {\n  \
    \    int v = q[ql++];\n      if (v == t) return;\n      for (int e = head[v];\
    \ e < head[v + 1]; ++e) {\n        const auto &nx = tos[e];\n        T dnx = dist[v]\
    \ + nx.second;\n        if (dist[nx.first] > dnx) {\n          dist[nx.first]\
    \ = dnx, prev[nx.first] = v;\n          if (nx.second) {\n            q[qr++]\
    \ = nx.first;\n          } else {\n            q[--ql] = nx.first;\n         \
    \ }\n        }\n      }\n    }\n  }\n\n  // Dial's algorithm\n  // - Requirement:\
    \ wmin >= 0\n  // - Complexity: O(wmax * V + E)\n  void dial(int s, int t = INVALID)\
    \ {\n    assert(0 <= s and s < V);\n    build();\n    dist.assign(V, INF), prev.assign(V,\
    \ INVALID);\n    dist[s] = 0;\n    vector<vector<pair<int, T>>> q(wmax + 1);\n\
    \    q[0].emplace_back(s, dist[s]);\n    int ninq = 1;\n\n    int cur = 0;\n \
    \   T dcur = 0;\n    for (; ninq; ++cur, ++dcur) {\n      if (cur == wmax + 1)\
    \ cur = 0;\n      while (!q[cur].empty()) {\n        int v = q[cur].back().first;\n\
    \        T dnow = q[cur].back().second;\n        q[cur].pop_back(), --ninq;\n\
    \        if (v == t) return;\n        if (dist[v] < dnow) continue;\n\n      \
    \  for (int e = head[v]; e < head[v + 1]; ++e) {\n          const auto &nx = tos[e];\n\
    \          T dnx = dist[v] + nx.second;\n          if (dist[nx.first] > dnx) {\n\
    \            dist[nx.first] = dnx, prev[nx.first] = v;\n            int nxtcur\
    \ = cur + int(nx.second);\n            if (nxtcur >= int(q.size())) nxtcur -=\
    \ q.size();\n            q[nxtcur].emplace_back(nx.first, dnx), ++ninq;\n    \
    \      }\n        }\n      }\n    }\n  }\n\n  // Solver for DAG\n  // - Requirement:\
    \ graph is DAG\n  // - Complexity: O(V + E)\n  bool dag_solver(int s) {\n    assert(0\
    \ <= s and s < V);\n    build();\n    dist.assign(V, INF), prev.assign(V, INVALID);\n\
    \    dist[s] = 0;\n    vector<int> indeg(V, 0);\n    vector<int> q(V * 2);\n \
    \   int ql = 0, qr = 0;\n    q[qr++] = s;\n    while (ql < qr) {\n      int now\
    \ = q[ql++];\n      for (int e = head[now]; e < head[now + 1]; ++e) {\n      \
    \  const auto &nx = tos[e];\n        ++indeg[nx.first];\n        if (indeg[nx.first]\
    \ == 1) q[qr++] = nx.first;\n      }\n    }\n    ql = qr = 0;\n    q[qr++] = s;\n\
    \    while (ql < qr) {\n      int now = q[ql++];\n      for (int e = head[now];\
    \ e < head[now + 1]; ++e) {\n        const auto &nx = tos[e];\n        --indeg[nx.first];\n\
    \        if (dist[nx.first] > dist[now] + nx.second)\n          dist[nx.first]\
    \ = dist[now] + nx.second, prev[nx.first] = now;\n        if (indeg[nx.first]\
    \ == 0) q[qr++] = nx.first;\n      }\n    }\n    return *max_element(indeg.begin(),\
    \ indeg.end()) == 0;\n  }\n\n  // Retrieve a sequence of vertex ids that represents\
    \ shortest path [s, ...,\n  // goal] If not reachable to goal, return {}\n  vector<int>\
    \ retrieve_path(int goal) const {\n    assert(int(prev.size()) == V);\n    assert(0\
    \ <= goal and goal < V);\n    if (dist[goal] == INF) return {};\n    vector<int>\
    \ ret{goal};\n    while (prev[goal] != INVALID) {\n      goal = prev[goal];\n\
    \      ret.push_back(goal);\n    }\n    reverse(ret.begin(), ret.end());\n   \
    \ return ret;\n  }\n\n  void solve(int s, int t = INVALID) {\n    if (wmin >=\
    \ 0) {\n      if (single_positive_weight) {\n        zero_one_bfs(s, t);\n   \
    \   } else if (wmax <= 10) {\n        dial(s, t);\n      } else {\n        if\
    \ ((long long)V * V < (E << 4)) {\n          dijkstra_vquad(s, t);\n        }\
    \ else {\n          dijkstra(s, t);\n        }\n      }\n    } else {\n      bellman_ford(s,\
    \ V);\n    }\n  }\n\n  // Warshall-Floyd algorithm\n  // - Requirement: no negative\
    \ loop\n  // - Complexity: O(E + V^3)\n  vector<vector<T>> floyd_warshall() {\n\
    \    build();\n    vector<vector<T>> dist2d(V, vector<T>(V, INF));\n    for (int\
    \ i = 0; i < V; i++) {\n      dist2d[i][i] = 0;\n      for (const auto &e : edges)\
    \ {\n        int s = get<0>(e), t = get<1>(e);\n        dist2d[s][t] = min(dist2d[s][t],\
    \ get<2>(e));\n      }\n    }\n    for (int k = 0; k < V; k++) {\n      for (int\
    \ i = 0; i < V; i++) {\n        if (dist2d[i][k] == INF) continue;\n        for\
    \ (int j = 0; j < V; j++) {\n          if (dist2d[k][j] == INF) continue;\n  \
    \        dist2d[i][j] = min(dist2d[i][j], dist2d[i][k] + dist2d[k][j]);\n    \
    \    }\n      }\n    }\n    return dist2d;\n  }\n\n  void to_dot(string filename\
    \ = \"shortest_path\") const {\n    ofstream ss(filename + \".DOT\");\n    ss\
    \ << \"digraph{\\n\";\n    build();\n    for (int i = 0; i < V; i++) {\n     \
    \ for (int e = head[i]; e < head[i + 1]; ++e) {\n        ss << i << \"->\" <<\
    \ tos[e].first << \"[label=\" << tos[e].second << \"];\\n\";\n      }\n    }\n\
    \    ss << \"}\\n\";\n    ss.close();\n    return;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path.hpp
  requiredBy: []
  timestamp: '2022-08-19 21:06:49+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path.hpp
- /library/graph/shortest_path.hpp.html
title: graph/shortest_path.hpp
---