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
#include<climits>
#include<sstream>
using namespace std;
#define maxn 105
const long long inf=200000000000;
int n,m;
long long g[maxn][maxn],g_[maxn][maxn];

int main(){

    int i,j,k,x,y,val;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j)
                g[i][j]=0;
            else g[i][j]=inf;
    for(i=0;i<m;i++){
        cin>>x>>y>>val;
        g[x][y]=val;
    }
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(g[i][k]!=inf &&g[k][j]!=inf &&g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g_[i][j]=g[i][j];
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                 if(g[i][k]!=inf &&g[k][j]!=inf &&g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    bool negative=false;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(g[i][j]!=g_[i][j])
                negative=true;
    if(negative)
        cout<<"NEGATIVE CYCLE"<<endl;
    else{
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++)
                if(g[i][j]==inf)
                    cout<<"INF ";
                else
                    cout<<g[i][j]<<" ";
            if(g[i][n-1]==inf)
                    cout<<"INF"<<endl;
                else
                    cout<<g[i][n-1]<<endl;
        }
    }
    return 0;
}

