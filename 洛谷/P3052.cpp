#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 7;
int f[19][N], w[19];
int main() {
  int n, W;
  cin >> n >> W;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  int U = (1 << n) - 1;
  memset(f, 0x3f, sizeof(f));
  f[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int s = 0; s <= U; ++s) {
      if (f[i][s] <= W) {
        for (int t = 1; t <= n; ++t) {
          int T = 1 << (t - 1);
          if ((s & T) == 0) {
            if (f[i][s] + w[t] <= W)
              f[i][s | T] = min(f[i][s | T], f[i][s] + w[t]);
            else
              f[i + 1][s | T] = min(f[i + 1][s | T], w[t]);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (f[i][U] <= W) {
      cout << i << endl;
      break;
    }
  return 0;
}