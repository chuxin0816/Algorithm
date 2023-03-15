#include <bits/stdc++.h>
using namespace std;
const int N = 130;
int a[N][N], temp[N], dp[N], ans;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    memset(temp, 0, sizeof(temp));
    for (int j = i; j <= n; ++j) {
      memset(dp, 0, sizeof(dp));
      for (int k = 1; k <= n; ++k) {
        temp[k] += a[j][k];
        dp[k] = max(dp[k], dp[k - 1] + temp[k]);
        ans = max(ans, dp[k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}