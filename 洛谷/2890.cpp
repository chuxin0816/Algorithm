#include <bits/stdc++.h>
using namespace std;
char str[2010];
int n, m, a[255][2], f[2010][2010];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> str[i];
  for (int i = 1; i <= n; ++i) {
    char x;
    cin >> x;
    cin >> a[x][0] >> a[x][1];
  }
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= m; ++i) f[i][i] = 0;
  for (int i = 0; i <= m + 1; ++i) {
    for (int j = 0; j < i; ++j) f[i][j] = 0;
  }
  for (int len = 1; len < m; ++len) {
    for (int i = 1; len + i <= m; ++i) {
      int j = len + i;
      f[i][j] = min(f[i + 1][j] + min(a[str[i]][0], a[str[i]][1]),
                    f[i][j - 1] + min(a[str[j]][0], a[str[j]][1]));
      if (str[i] == str[j]) {
        if (j - i == 1)
          f[i][j] = 0;
        else
          f[i][j] = min(f[i][j], f[i + 1][j - 1]);
      }
    }
  }
  cout << f[1][m] << endl;
  return 0;
}