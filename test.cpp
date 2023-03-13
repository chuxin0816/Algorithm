#include <bits/stdc++.h>
using namespace std;
#define str s
#define len k
const int N = 2010;
int n, m;
char s[N];
int c[255][2];
int f[N][N];
int main() {
  cin >> m >> n;
  scanf("%s", s + 1);
  for (int i = 1; i <= m; ++i) {
    char x;
    cin >> x;
    cin >> c[x][0] >> c[x][1];
  }
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; ++i) f[i][i] = 0;
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j < i; ++j) f[i][j] = 0;
  }
  for (int len = 1; len < n; ++len) {
    for (int i = 1; len + i <= n; ++i) {
      int j = len + i;
      f[i][j] = min(f[i + 1][j] + min(c[str[i]][0], c[str[i]][1]),
                    f[i][j - 1] + min(c[str[j]][0], c[str[j]][1]));
      if (str[i] == str[j]) {
        if (j - i == 1)
          f[i][j] = 0;
        else
          f[i][j] = min(f[i][j], f[i + 1][j - 1]);
      }
    }
  }
  /* for (int k = 1; k < n; ++k) {
    for (int i = 1; k + i <= n; ++i) {
      int j = k + i;
      f[i][j] = min(f[i + 1][j] + min(c[s[i]][0], c[s[i]][1]),
                    f[i][j - 1] + min(c[s[j]][0], c[s[j]][1]));
      if (s[i] == s[j]) {
        if (j - i == 1)
          f[i][j] = 0;
        else
          f[i][j] = min(f[i][j], f[i + 1][j - 1]);
      }
    }
  } */
  cout << f[1][n] << endl;
}