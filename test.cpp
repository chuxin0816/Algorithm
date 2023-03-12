#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 20, maxt = 1<<20;
int n, m, t; //n个点，m条边，t个状态
int u, v;
vector<int> g[maxn];
int f[maxt][maxn]; // f[i][j]表示状态i下，lowbit(i) -> j的路径数
int ans = 0; //无向环数（有反向重复和双边无效环重复）
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m; t = (1<<n);
    for(int i=1; i<=m; i++){
        cin >> u >> v; //注意，根据二进制的性质，必须从0开始编号
        g[u-1].push_back(v-1); g[v-1].push_back(u-1);
    }
    for(int i=0; i<n; i++) f[1<<i][i] = 1; //到自己的路径数是1
    for(int i=1; i<t; i++) //枚举状态
    for(int j=0; j<n; j++){ //枚举起点
        if(!f[i][j]) continue; //没有路径，跳过
        for(int k : g[j]){ //枚举终点
            if((1<<k) < (i&-i)) continue; //不满足起点要求，去重
            if((1<<k) & i){
                if((1<<k) == (i&-i)) ans += f[i][j]; //回到起点，统计圈数
            } else f[i|(1<<k)][k] += f[i][j]; //新的一条路，统计路径数
        }
    }
    cout << (ans-m)/2; //去除双边无效环和反向重复环
}
