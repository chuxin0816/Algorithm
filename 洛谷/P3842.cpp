#include <iostream>
using namespace std;
const int N = 2e4 + 7;
int l[N], r[N], f[N][2];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  f[1][0] = r[1] - l[1] + r[1] - 1, f[1][1] = r[1] - 1;
  for (int i = 2; i <= n; ++i) {
    f[i][0] = min(f[i - 1][0] + abs(r[i] - l[i - 1]),
                  f[i - 1][1] + abs(r[i] - r[i - 1])) +
              r[i] - l[i] + 1;
    f[i][1] = min(f[i - 1][0] + abs(l[i] - l[i - 1]),
                  f[i - 1][1] + abs(l[i] - r[i - 1])) +
              r[i] - l[i] + 1;
  }
  cout << min(f[n][0] + n - l[n], f[n][1] + n - r[n]) << endl;
  return 0;
}