#include <bits/stdc++.h>
using namespace std;
double p(int x, int y) {
  double p0 = 1.0 * x / (x + y);
  double p1 = 1.0 * y / (x + y);
  return -p0 * x * log2(p0) - p1 * y * log2(p1);
}
int main() {
  int n = 23333333;
  int l = 1, r = (n + 1) >> 1;
  double ans = 11625907.5798;
  while (l < r) {
    int m = (l + r) >> 1;
    double val = p(m, n - m);
    if (val < ans)
      l = m + 1;
    else
      r = m;
  }
  cout << l << endl;
}