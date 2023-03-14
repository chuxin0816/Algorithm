#include <bits/stdc++.h>
using namespace std;
const int N = 25000;
int a[101];
int t, n;
int main() {
  cin >> t;
  while (t--) {
    int maxa = 0, val = 0;
    int vis[N] = {0};
    cin >> n;
    for (int j = 1; j <= n; ++j) {
      cin >> a[j];
      maxa = max(maxa, a[j]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
      if (vis[a[i]]) continue;
      val++, vis[a[i]] = 1;
      for (int j = a[i]; j <= N; ++j)
        if (vis[j - a[i]]) vis[j] = 1;
    }
    cout << val << endl;
  }
  return 0;
}