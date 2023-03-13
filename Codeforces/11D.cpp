#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
const int N = 1 << 20;
long long f[N][20], n, m, t, ans;
int main() {
  cin >> n >> m;
  t = 1 << n;
  vector<int> adl[20];
  for (int i = 0; i < m; ++i) {z
    int a, b;
    cin >> a >> b;
    adl[a].push_back(b);
    adl[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) f[1 << (i - 1)][i] = 1;
  for (int i = 1; i < t; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!f[i][j]) continue;
      for (auto k : adl[j]) {
        int K = 1 << (k - 1);
        if (K < lowbit(i)) continue;
        if (K & i) {
          if (K == lowbit(i)) ans += f[i][j];
        } else
          f[i | K][k] += f[i][j];
      }
    }
  }
  cout << (ans - m) / 2 << endl;
  return 0;
}