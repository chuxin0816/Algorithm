#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int f[N][N];
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> f[i][i];
  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      for (int k = i; k < j; ++k) {
        if (f[i][k] == f[k + 1][j] && f[i][k]) {
          f[i][j] = max(f[i][j], f[i][k] + 1);
          ans = max(ans, f[i][j]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}