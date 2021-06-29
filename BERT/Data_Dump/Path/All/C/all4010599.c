#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (2147483647)
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define MAXV 110
int V,E;
vector<vector<ll> >G(MAXV,vector<ll>(MAXV,INF));//init
ll r(){ll x;cin>>x;return x;}//input longlong
void solve()
{
    cin>>V>>E;
    REP(i,V)G[i][i]=0;//init
    REP(i,E)G[r()][r()]=r();//input
    //floyd-warshall //jump when i->k=inf or k->j=inf
    REP(k,V)REP(i,V)REP(j,V)G[i][j]=(G[i][k]==INF||G[k][j]==INF?G[i][j]:min(G[i][j],G[i][k]+G[k][j]));
    //if can RELAX,negative cycle
    REP(i,V)REP(j,V)if(G[i][j]<0)REP(k,V)if(G[i][j]!=min(G[i][j],G[i][k]+G[k][j])){cout<<"NEGATIVE CYCLE"<<endl;return;}
    //output //attenion!! presentation
    REP(i,V)REP(j,V)cout<<(G[j][i]==INF?"INF":to_string(G[j][i]))<<(j==V-1?"\n":" ");
}
int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
