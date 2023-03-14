#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int f[N], ans;
vector<int> g[N];
char vis[N], s[N], current_c;
bool hascycle;
void Check_Cycle(int u) {
  vis[u] = -1;
  for (auto e : g[u]) {
    if (vis[e] == -1) hascycle = 1;
    if (vis[e]) continue;
    Check_Cycle(e);
  }
  vis[u] = 1;
}
int dfs(int u) {
  if (vis[u]) return f[u];
  vis[u] = 1, f[u] = 0;
  for (auto e : g[u]) {
    f[u] = max(f[u], dfs(e));
  }
  return f[u] += s[u] == current_c;
}
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) Check_Cycle(i);
  if (hascycle) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    current_c = i;
    memset(vis, 0, n + 1);
    for (int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
  }
  cout << ans << endl;
  return 0;
}