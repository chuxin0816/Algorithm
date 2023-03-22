#include <bits/stdc++.h>
using namespace std;
const int N = 310;
struct Edge {
  int next, to;
};
Edge e[N];
int head[N], cnt, dp[N][N], n, m;
void add(int u, int v) {
  e[++cnt].next = head[u];
  e[cnt].to = v;
  head[u] = cnt;
}
void dfs(int u, int s) {
  for (int i = head[u]; i; i = e[i].next) dfs(e[i].to, s - 1);
  for (int i = head[u]; i; i = e[i].next)
    for (int j = m, v = e[i].to; j > 0; --j)
      for (int k = 1; k < j; ++k)
        dp[u][j] = max(dp[u][j], dp[v][j - k] + dp[u][k]);
}
int main() {
  cin >> n >> m;
  ++m;
  for (int i = 1; i <= n; ++i) {
    int u;
    cin >> u >> dp[i][1];
    add(u, i);
  }
  dfs(0, m);
  cout << dp[0][m] << endl;
  return 0;
}