#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 7;
int r[N];
int f[N][2];
vector<int> g[N];
void dfs(int u, int fa) {
  for (auto e : g[u]) {
    if (e == fa) continue;
    dfs(e, u);
    f[u][0] += max(f[e][0], f[e][1]);
    f[u][1] += f[e][0];
  }
  f[u][1] += r[u];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> r[i];
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  cout << max(f[1][0], f[1][1]) << endl;
  return 0;
}