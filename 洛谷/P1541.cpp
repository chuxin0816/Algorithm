#include <iostream>
using namespace std;
int f[125][125][125][125], num[355], g[5];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> num[i];
  for (int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    g[x]++;
  }
  f[0][0][0][0] = num[1];
  for (int a = 0; a <= g[1]; ++a)
    for (int b = 0; b <= g[2]; ++b)
      for (int c = 0; c <= g[3]; ++c)
        for (int d = 0; d <= g[4]; ++d) {
          int pos = 1 + a + b * 2 + c * 3 + d * 4;
          if (a)
            f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + num[pos]);
          if (b)
            f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + num[pos]);
          if (c)
            f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + num[pos]);
          if (d)
            f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + num[pos]);
        }
  cout << f[g[1]][g[2]][g[3]][g[4]] << endl;
  return 0;
}