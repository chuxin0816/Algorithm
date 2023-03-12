#include <bits/stdc++.h>
using namespace std;
const int N = 507;
int a[N] = {-1}, b[N] = {-1}, dp[N][N], pr[N][N];
int s[N], pos, sp;
int main() {
  int n, m, val = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] != b[j]) {
        dp[i][j] = dp[i - 1][j];
        pr[i][j] = pr[i - 1][j];
      } else {
        for (int k = 0; k < j; ++k) {
          if (a[i] > b[k] && dp[i - 1][k] + 1 > dp[i][j]) {
            dp[i][j] = dp[i - 1][k] + 1;
            pr[i][j] = k;
          }
        }
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    if (dp[n][j] > val) {
      val = dp[n][j];
      pos = j;
    }
  }
  while (pos) {
    s[++sp] = b[pos];
    pos = pr[n][pos];
  }
  cout << val << endl;
  while (sp) cout << s[sp--] << ' ';
  cout << endl;
  return 0;
}