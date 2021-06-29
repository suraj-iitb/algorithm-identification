#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

const ll inf=1e15;
const int MAX_V=100;

int V,E;
ll G[MAX_V+1][MAX_V+1];

int main() {
  cin>>V>>E;
  rep(i, V) rep(j, V) G[i][j]=(i!=j)*inf;
  rep(i, V) G[i][i]=0;
  rep(i, E) {
    int a,b,c; cin>>a>>b>>c;
    G[a][b]=c;
  }
  rep(k, V) rep(i, V) rep(j, V) G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
  bool ok=true;
  rep(i, V) if (G[i][i]<0) ok=false;
  if (ok) {
    rep(i, V) {
      rep(j, V) {
        if (j) cout<<" ";
        if (G[i][j]>inf/2) cout<<"INF";
        else cout<<G[i][j];
      }
      cout<<endl;
    }
  }
  else cout<<"NEGATIVE CYCLE"<<endl;
}

