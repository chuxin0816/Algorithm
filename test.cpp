#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
struct puke
{
 string content;
 int index;
};
int judge(char number)
{
 if (number == 'A') return 13;
 if (number == 'K') return 12;
 if (number == 'Q') return 11;
 if (number == 'J') return 10;
 if (number == '1') return 9;
 if (number == '9') return 8;
 if (number == '8') return 7;
 if (number == '7') return 6;
 if (number == '6') return 5;
 if (number == '5') return 4;
 if (number == '4') return 3;
 if (number == '3') return 2;
 if (number == '2')return 1;
 else return 0;
}
bool cmp(puke a, puke b)
{
 return a.index < b.index;
}
string a = "黑", b = "红", c = "梅", d = "方";
int main()
{
 int T; cin >> T;
 while (T--)
 {
  int n; cin >> n;
  puke* p = new puke[n];
  for (int i = 0; i < n; i++)
  {
   cin >> p[i].content;
   if (p[i].content == "大王") p[i].index = 54;
   if (p[i].content == "小王") p[i].index = 53;
   if (p[i].content[0] == a[0])
   {
    p[i].index = judge(p[i].content[2]) + 39;
   }
   if (p[i].content[0] ==b[0])
   {
    p[i].index = judge(p[i].content[2]) + 26;
cout<<typeid(p[i].content[2]).name()<<endl;
   }
   if (p[i].content[0] == c[0])
   {
    p[i].index = judge(p[i].content[2]) + 13;
   }
   if (p[i].content[0] == d[0])
   {
    p[i].index = judge(p[i].content[2]);
   }
  }
  for (int i = 0; i < n; i++) cout << p[i].index<<endl;
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++)
  {
   if (i == n - 1) cout << p[i].content << endl;
   else cout << p[i].content << " ";
  }
 }
}