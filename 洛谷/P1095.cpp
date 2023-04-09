#include <iostream>
using namespace std;
int main() {
  int m, s, t, s1 = 0, s2 = 0;
  cin >> m >> s >> t;
  for (int i = 1; i <= t; ++i) {
    s1 += 17;
    if (m >= 10) {
      s2 += 60;
      m -= 10;
    } else
      m += 4;
    if (s2 > s1) s1 = s2;
    if (s1 >= s) {
      cout << "Yes\n" << i << endl;
      return 0;
    }
  }
  cout << "No\n" << s1 << endl;
  return 0;
}