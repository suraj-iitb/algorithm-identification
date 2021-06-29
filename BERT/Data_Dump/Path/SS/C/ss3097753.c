#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#define Vmaxn 100010
#define Emaxn 500010
#define inf 2147483646

using namespace std;

struct Node
{
    int x,y,val,pre;
};
int g_[Vmaxn];
Node g[Emaxn];//动态数组存储

int n,m,r;
int dis[Vmaxn];
bool h[Vmaxn];
queue<int> q;
void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int main()
{
    int i,j,k,t,ans;
    int p,p_;
    read(n),read(m),read(r);
    memset(g_,-1,sizeof g_);
    for(i=0;i<m;i++)
    {
        read(g[i].x),read(g[i].y),read(g[i].val);
        g[i].pre=g_[g[i].x];
        g_[g[i].x]=i;
    }

    for(i=0;i<n;i++)
        dis[i]=inf,h[i]=true;
    dis[r]=0,h[r]=false;
    q.push(r);

    while(!q.empty())
    {
        p=q.front();q.pop();h[p]=true;
        j=g_[p];
        while(j!=-1)
        {
            p_=g[j].y;
            if(dis[p]+g[j].val<dis[p_])
            {
                dis[p_]=dis[p]+g[j].val;
                if(h[p_])
                {
                    q.push(p_);
                    h[p_]=false;
                }
            }
            j=g[j].pre;
        }
    }
    for(i=0;i<n;i++)
        if(dis[i]==inf)
            printf("INF\n");
        else
            printf("%d\n",dis[i]);
    return 0;
}

