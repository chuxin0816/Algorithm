#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
  sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
  for (auto e : a) cout << e << ' ';
  cout << endl;
  return 0;
}
