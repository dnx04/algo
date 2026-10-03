void dfs_len(int u, int p) {
  sub_len[u] = 1;
  for (int v : adj[u]) {
    if (v != p && !removed[v]) {
      dfs_len(v, u);
      sub_len[u] += sub_len[v];
    }
  }
}

int find_centroid(int u, int p, int total) {
  for (int v : adj[u]) {
    if (v != p && !removed[v] && sub_len[v] > total / 2) {
      return find_centroid(v, u, total);
    }
  }
  return u;
}

void decompose(int u, int p) {
  dfs_len(u, -1);
  int centroid = find_centroid(u, -1, sub_len[u]);

  par_centroid[centroid] = p;
  removed[centroid] = true;

  for (int v : adj[centroid]) {
    if (!removed[v]) {
      decompose(v, centroid);
    }
  }
}
