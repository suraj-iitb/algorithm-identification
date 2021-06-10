#include<bits/stdc++.h>
#define inf 999999999999999
using namespace std;
int n,m;
long long dis[105][105];
void init()
{
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	dis[i][j]=(i==j)? 0:inf;
}
int main()
{
	cin>>n>>m;
	init();
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		dis[x][y]=w;
	}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(dis[i][k]!=inf&&dis[k][j]!=inf) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=0;i<n;i++)
	if(dis[i][i]<0) {cout<<"NEGATIVE CYCLE"<<endl;return 0;}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j) cout<<" ";
			if(dis[i][j]==inf) cout<<"INF";
			else cout<<dis[i][j];
		}
		cout<<endl;
	}
	return 0;
}
