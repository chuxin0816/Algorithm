#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N];
int dp[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(0, dp[i - 1]) + a[i];
  }
  int val = dp[1];
  for (int i = 2; i <= n; ++i) val = max(val, dp[i]);
  cout << val << endl;
  return 0;
}
