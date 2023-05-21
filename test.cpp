#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using PII = pair<int, int>;
const int N = 150010;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;
void insert(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int Dijkstra() {
  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, 1});
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();
    int dis = t.first, ver = t.second;
    if (st[ver]) continue;
    st[ver] = 1;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dis + w[i] < d[j]) {
        d[j] = dis + w[i];
        heap.push({d[j], j});
      }
    }
  }
  return d[n] == 0x3f3f3f3f ? -1 : d[n];
}
int main() {
  memset(h, -1, sizeof(h));
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    insert(a, b, c);
  }
  cout << Dijkstra() << endl;
}