#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,l,r) for(int i=l;i<r;i++)
const int inf=2e9+10;
const ll INF=9e18+10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

const ll MOD=1e9+7;

struct edge{
    int from,to,cost;
    edge(){}
    edge(int from,int to,int cost):from(from),to(to),cost(cost){}
};

int solve(int n,vector<edge> &eg,int u,ll dp[]){
    rep(i,n)dp[i]=INF;
    dp[u]=0;
    rep(i,n){
        int change=0;
        rep(j,eg.size()){
            edge e=eg[j];
            if(dp[e.from]!=INF&&dp[e.to]>dp[e.from]+e.cost){
                //INF値に加算が起こる自体は避けねば
                dp[e.to]=dp[e.from]+e.cost;
                change=1;
            }
        }
        if(!change)break;
        if(i==n-1)return -1;
    }
    return 1;
}

int main(){
    int n,m;cin>>n>>m;
    vector<edge> eg(m);
    rep(i,m){
        int s,t,c;
        scanf("%d %d %d",&s,&t,&c);
        eg[i]=edge(s,t,c);
    }
    //rep(i,m)cout<<eg[i].from<<" "<<eg[i].to<<" "<<eg[i].cost<<endl;;


    ll dp[n];
    rep(i,n){
        if(solve(n,eg,i,dp)==-1){
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    rep(i,n){
        solve(n,eg,i,dp);
        rep(j,n){
            if(j!=0)cout<<" ";
            if(dp[j]==INF)cout<<"INF";
            else cout<<dp[j];
        }
        printf("\n");
    }


    return 0;
}
