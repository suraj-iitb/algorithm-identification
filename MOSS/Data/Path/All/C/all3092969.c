#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int I=X;I<Y;I++)
#define REP(I,X,Y) for(int I=Y-1;I>=X;I--)
#define INF 1000000007
#define LINF 1000000000000000007
typedef long long ll;
using namespace std;

ll adj[100][100];

int main(){
  FOR(i,0,100)FOR(j,0,100)adj[i][j] = LINF;
  FOR(i,0,100)adj[i][i] = 0;
  ll V,E,s,t,d;
  cin >> V >> E;
  FOR(i,0,E){
    cin >> s >> t >> d;
    adj[s][t] = d;
  }
  FOR(i,0,V)FOR(j,0,V)FOR(k,0,V)if(adj[j][i] != LINF && adj[i][k] != LINF)adj[j][k] = min(adj[j][k],adj[j][i]+adj[i][k]);
  FOR(i,0,V)FOR(j,0,V)FOR(k,0,V){
    if(adj[j][i] != LINF && adj[i][k] != LINF)if(adj[j][k] > adj[j][i]+adj[i][k]){
      puts("NEGATIVE CYCLE");
      return 0;
    }
  }
  FOR(i,0,V){
    FOR(j,0,V)cout << (adj[i][j] == LINF ? "INF" :to_string(adj[i][j])) << (j != V-1 ? " " : "");cout << endl;
  }
}

