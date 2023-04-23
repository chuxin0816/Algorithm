#include <bits/stdc++.h>
using namespace std;
string mon[] = {"01", "02", "03", "04", "05", "06",
                "07", "08", "09", "10", "11", "12"};
string day[] = {"01", "02", "03", "04", "05", "06", "07", "08",
                "09", "10", "11", "12", "13", "14", "15", "16",
                "17", "18", "19", "20", "21", "22", "23", "24",
                "25", "26", "27", "28", "29", "30", "31"};
int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(string str, string date) {
  int n = str.size();
  for (int i = 0, j = 0; i < n; ++i) {
    if (str[i] == date[j]) ++j;
    if (j == 8) return true;
  }
  return false;
}
int main() {
  int sum = 0;
  string str = "";
  for (int i = 0; i < 100; ++i) {
    string temp;
    cin >> temp;
    str += temp;
  }
  string year = "2023";
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < md[i]; ++j) {
      string date = year + mon[i] + day[j];
      if (check(str, date)) sum++;
    }
  }
  cout << sum << endl;
  return 0;
}