#include <bits/stdc++.h>
using namespace std;
int dp[11][11], a[11];
void init() {
  for (int i = 0; i < 10; ++i) dp[1][i] = 1;
  for (int i = 2; i <= 10; ++i)
    for (int j = 0; j < 10; ++j)
      for (int k = 0; k < 10; ++k)
        if (abs(j - k) >= 2) dp[i][j] += dp[i - 1][k];
}
int solve(int x) {
  int len = 0, ans = 0;
  memset(a, 0, sizeof a);
  while (x) {
    a[++len] = x % 10;
    x /= 10;
  }
  for (int i = 1; i < len; ++i)
    for (int j = 1; j < 10; ++j) ans += dp[i][j];
  for (int i = 1; i < a[len]; ++i) ans += dp[len][i];
  for (int i = len - 1; i > 0; --i) {
    for (int j = 0; j < a[i]; ++j)
      if (abs(a[i + 1] - j) >= 2) ans += dp[i][j];
    if (abs(a[i + 1] - a[i]) < 2) break;
  }
  return ans;
}
int main() {
  int a, b;
  cin >> a >> b;
  init();
  cout << solve(b + 1) - solve(a) << endl;
  return 0;
}