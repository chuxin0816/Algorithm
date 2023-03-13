#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int f[59][N];
int main() {
  int n, ans;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    f[a][i] = i + 1;
  }
  for (int i = 2; i <= 58; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!f[i][j]) f[i][j] = f[i - 1][f[i - 1][j]];
      if (f[i][j]) ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}