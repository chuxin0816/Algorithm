#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int a[N], f[N][N], g[N][N], sum[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n * 2; ++i) sum[i] = sum[i - 1] + a[i];
  for (int len = 2; len <= n; ++len) {
    for (int r = len; r <= n * 2; ++r) {
      int l = r - len + 1;
      int val = sum[r] - sum[l - 1];
      g[l][r] = 1e9;
      for (int k = l; k < r; ++k) {
        f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + val);
        g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + val);
      }
    }
  }
  int M = 0, m = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    M = max(M, f[i][n + i - 1]);
    m = min(m, g[i][n + i - 1]);
  }
  cout << m << endl << M << endl;
  return 0;
}