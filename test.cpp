#include<iostream>
#include<cstdio>
#define N 61
#define M 270007
using namespace std;
int n,ans;
int f[N][M];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
		int in;
		scanf("%d",&in);
		f[in][i]=i+1;
	}
    for(int i=2;i<=58;++i)
        for(int j=1;j<=n;++j)
        {
            if(!f[i][j]) 
				f[i][j]=f[i-1][f[i-1][j]];
            if(f[i][j]) 
				ans=i;
        }
    printf("%d",ans);
}