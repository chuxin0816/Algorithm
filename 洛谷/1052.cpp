#include <bits/stdc++.h>
using namespace std;
const int N = 300 * 105;
int f[N], l, s, t, m, cnt;
bool vis[N];
int stone[105], a[105];
int main() {
  cin >> l >> s >> t >> m;
  for (int i = 1; i <= m; ++i) cin >> stone[i];
  sort(stone + 1, stone + m + 1);
  int base = s * t;
  if (s == t) {
    for (int i = 1; i <= m; ++i) {
      if (stone[i] % s == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    int len = stone[i] - stone[i - 1];
    if (len >= base) len = base;
    a[i] = a[i - 1] + len;
    vis[a[i]] = 1;
  }
  l = a[m] + base;
  memset(f, 0x7f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= l; ++i) {
    for (int j = s; j <= t && i - j >= 0; ++j) {
      if (!vis[i])
        f[i] = min(f[i], f[i - j]);
      else
        f[i] = min(f[i], f[i - j] + 1);
    }
  }
  int ans = 10005;
  for (int i = a[m]; i <= l; ++i) ans = min(ans, f[i]);
  cout << ans << endl;
  return 0;
}