#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[13][2][13][2];
int num[13];
ll dfs(int len, bool nolimit, int sum, int lead, int d) {
  if (len == 0) return sum;
  if (f[len][nolimit][sum][lead] != -1) return f[len][nolimit][sum][lead];
  ll val = 0;
  for (int i = 0; i < 10; ++i) {
    if (!nolimit && i > num[len]) break;
    val += dfs(len - 1, nolimit || (i < num[len]),
               sum + ((i == d) && (!lead || i)), lead && (i == 0), d);
  }
  f[len][nolimit][sum][lead] = val;
  return val;
}
ll solve(ll x, int d) {
  int len = 0;
  while (x) {
    num[++len] = x % 10;
    x /= 10;
  }
  memset(f, -1, sizeof f);
  return dfs(len, 0, 0, 1, d);
}
int main() {
  ll a, b;
  cin >> a >> b;
  for (int i = 0; i < 10; ++i) cout << solve(b, i) - solve(a - 1, i) << ' ';
  cout << endl;
  return 0;
}