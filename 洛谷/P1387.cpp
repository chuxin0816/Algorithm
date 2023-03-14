#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N][105], f[N][105], val;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        val = max(val, f[i][j]);
      }
    }
  }
  cout << val << endl;
  return 0;
}