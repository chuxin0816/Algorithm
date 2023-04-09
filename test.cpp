#include <iostream>
using namespace std;
int main() {
  int a[] = {1, 3, 2, 4, 6, 2, 9, 10, 6, 7};
  qsort(a, 10, sizeof(int),
        [](const void* a, const void* b) { return (*(int*)a - *(int*)b); });
  for (auto e : a) cout << e << endl;
  return 0;
}