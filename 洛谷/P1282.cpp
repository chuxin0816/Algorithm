#include <bits/stdc++.h>
using namespace std;
const int N = 1007, MAX = 1e9;
int a[N], b[N], f[N][6 * N];
int main() {
  int n, s = 0, ans = MAX, dif = MAX;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    s += a[i] + b[i];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 6 * n; ++j) f[i][j] = MAX;
  f[1][a[1]] = 0, f[1][b[1]] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j <= 6 * n; ++j) {
      if (j - a[i] >= 0) f[i][j] = min(f[i][j], f[i - 1][j - a[i]]);
      if (j - b[i] >= 0) f[i][j] = min(f[i][j], f[i - 1][j - b[i]] + 1);
    }
  for (int i = 1; i <= s; ++i)
    if (abs(i - (s - i)) < dif) {
      dif = abs(i - (s - i));
      ans = f[n][i];
    } else if (abs(i - (s - i)) == dif)
      ans = min(ans, f[n][i]);
  cout << ans << endl;
  return 0;
}