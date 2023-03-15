#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int a[N][N], f[N][N], l[N][N], r[N][N], h[N][N];
int main() {
  int n, m, ans1 = 0, ans2 = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      f[i][j] = 1;
      l[i][j] = r[i][j] = j;
      h[i][j] = 1;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (a[i][j] != a[i][j - 1]) l[i][j] = l[i][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = m - 1; j >= 1; --j)
      if (a[i][j] != a[i][j + 1]) r[i][j] = r[i][j + 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == a[i - 1][j - 1] && a[i][j - 1] != a[i][j] &&
          a[i - 1][j] != a[i][j]) {
        f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        ans1 = max(ans1, f[i][j]);
      }
      if (i > 1 && a[i][j] != a[i - 1][j]) {
        l[i][j] = max(l[i][j], l[i - 1][j]);
        r[i][j] = min(r[i][j], r[i - 1][j]);
        h[i][j] = h[i - 1][j] + 1;
      }
      ans2 = max(ans2, (r[i][j] - l[i][j] + 1) * h[i][j]);
    }
  cout << ans1 * ans1 << endl << ans2 << endl;
  return 0;
}