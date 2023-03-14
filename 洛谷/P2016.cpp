#include <bits/stdc++.h>
using namespace std;
const int N = 1600;
int f[N][2];
vector<int> g[N];
void dfs(int u, int fa) {
  for (auto e : g[u]) {
    if (e == fa) continue;
    dfs(e, u);
    f[u][1] += min(f[e][0], f[e][1]);
    f[u][0] += f[e][1];
  }
  f[u][1] += 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, k, b;
    cin >> a >> k;
    while (k--) {
      cin >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  dfs(0, -1);
  cout << min(f[0][0], f[0][1]) << endl;
  return 0;
}