#include <bits/stdc++.h>
using namespace std;
int main() {
  int m = 0, M = 0x7fff, n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    m = max(m, a / (b + 1) + 1);
    M = min(M, a / b);
  }
  cout << m << ' ' << M << endl;
  return 0;
}