//本题dp只能60分
#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int f[N][N];
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 1; k <= max(i, j); ++k) {
        if (k <= min(i, j) && f[i - k][j - k] == 0) {
          f[i][j] = 1;
          break;
        }
        if (k <= i && f[i - k][j] == 0) {
          f[i][j] = 1;
          break;
        }
        if (k <= j && f[i][j - k] == 0) {
          f[i][j] = 1;
          break;
        }
      }
    }
  }
  cout << f[a][b] << endl;
}