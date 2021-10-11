#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

/* Undirected Graph */
class Graph {
public:
  Graph(int v, int e)
      : V(v), E(e), adj(vector<vector<int>>(v + 1, vector<int>())){};
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++E;
  };
  /* adjacent edges to vertex v */
  vector<int> adjV(int v) const { return adj[v]; };

  friend class BFS;

private:
  int V;
  int E;
  vector<vector<int>> adj;
};

class BFS {
public:
  BFS(const Graph &, int, int);
  vector<int> distanceToStart() { return distanceTo; };

private:
  vector<bool> marked;
  vector<int> distanceTo;
  int start;
};

BFS::BFS(const Graph &G, int s, int edge_weight)
    : marked(G.V + 1, false), distanceTo(G.V + 1, -1), start(s) {
  size_t v;
  queue<size_t> q;
  q.push(s);
  marked[s] = true;
  distanceTo[s] = 0;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (size_t u : G.adjV(v))
      if (!marked[u]) {
        q.push(u);
        marked[u] = true;
        distanceTo[u] = edge_weight + distanceTo[v];
      }
  }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
  Graph G(n, 0);
  for (const vector<int> &e : edges)
    G.addEdge(e[0], e[1]);
  BFS bfs(G, s, 6);
  vector<int> res;
  vector<int> dis = bfs.distanceToStart();
  for (int i = 1; i < dis.size(); i++) {
    if (i == s)
      continue;
    res.push_back(dis[i]);
  }
  return res;
}

int main() {
  vector<vector<int>> vec = {{1, 2}, {1, 3}};
  auto res = bfs(4, 2, vec, 1);
}