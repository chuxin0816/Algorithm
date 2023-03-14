#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
int a[N][N], f[N][N], val;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j], f[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == a[i - 1][j - 1] && a[i][j - 1] != a[i][j] &&
          a[i - 1][j] != a[i][j]) {
        f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        val = max(val, f[i][j]);
      }
    }
  cout << val << endl;
  return 0;
}