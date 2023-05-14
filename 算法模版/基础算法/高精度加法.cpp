vector<int> add(const vector<int> &a, const vector<int> &b) {
  vector<int> c;
  int t = 0, len = max(a.size(), b.size());
  for (int i = 0; i < len || t; i++) {
    if (i < a.size()) t += a[i];
    if (i < b.size()) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  return c;
}