#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][10], f[N][20][5], ans = -2147483647;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  memset(f, -0x3f, sizeof(f));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 1; i < 4; ++i) f[0][0][i] = 0;
  if (m == 1) {
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= k; ++j) {
        f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
        if (j)
          f[i][j][1] =
              max(f[i - 1][j][1], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1])) +
              a[i][1];
      }
    cout << max(f[n][k][0], f[n][k][1]);
  } else {
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= k; ++j) {
        for (int t = 0; t <= 4; ++t)
          f[i][j][0] = max(f[i][j][0], f[i - 1][j][t]);
        if (j) {
          f[i][j][1] =
              max(f[i][j][1], max(f[i - 1][j][1], f[i - 1][j][4]) + a[i][1]);
          for (int t = 0; t <= 4; ++t)
            f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][t] + a[i][1]);
          f[i][j][2] =
              max(f[i][j][2], max(f[i - 1][j][2], f[i - 1][j][4]) + a[i][2]);
          for (int t = 0; t <= 4; ++t)
            f[i][j][2] = max(f[i][j][2], f[i - 1][j - 1][t] + a[i][2]);
          f[i][j][3] = max(f[i][j][3], f[i - 1][j][3] + a[i][1] + a[i][2]);
          for (int t = 0; t <= 4; ++t)
            f[i][j][3] =
                max(f[i][j][3], f[i - 1][j - 1][t] + a[i][1] + a[i][2]);
        }
        if (j > 1) {
          f[i][j][4] =
              max(f[i][j][4], max(max(f[i - 1][j - 1][1], f[i - 1][j - 1][2]),
                                  f[i - 1][j][4]) +
                                  a[i][1] + a[i][2]);
          for (int t = 0; t <= 4; ++t)
            f[i][j][4] =
                max(f[i][j][4], f[i - 1][j - 2][t] + a[i][1] + a[i][2]);
        }
      }
    for (int t = 0; t <= 4; ++t) ans = max(ans, f[n][k][t]);
    cout << ans << endl;
  }
  return 0;
}