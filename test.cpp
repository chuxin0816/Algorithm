#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 3e5+10;
int a[N],s[N];
vector<int> all;
vector<pair<int,int>> add,query;
int find(int x){
  int l=0,r=all.size()-1;
  while(l<r){
    int mid=l+r >>1;
    if(a[mid]>=x) r=mid;
    else l=mid+1;
  }
  return l+1;
}
int main(){
  int n,m;
  cin>>n>>m;
  while(n--){
    int x,c;
    cin>>x>>c;
    all.push_back(x);
    add.push_back({x,c});
  }
  while(m--){
    int l,r;
    cin>>l>>r;
    all.push_back(l),all.push_back(r);
    query.push_back({l,r});
  }
  sort(all.begin(),all.end());
  all.erase(unique(all.begin(),all.end()),all.end());
  for(auto e:add){
    int x = find(e.first);
    a[x]+=e.second;
  }
  for(int i=1;i<=all.size();i++) s[i]=s[i-1]+a[i];
  for(auto e:query){
    int l=find(e.first),r=find(e.second);
    cout<<s[r]-s[l-1]<<endl;
  }
}