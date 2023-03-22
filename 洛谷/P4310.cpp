#include <bits/stdc++.h>
using namespace std;
int dp[31], ans;
int main() {
  int n, a, k;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    k = 1;
    for (int j = 0; j < 31; ++j)
      if (1 << j & a) k = max(k, dp[j] + 1);
    for (int j = 0; j < 31; ++j)
      if (1 << j & a) dp[j] = k;
    ans = max(ans, k);
  }
  cout << ans << endl;
  return 0;
}