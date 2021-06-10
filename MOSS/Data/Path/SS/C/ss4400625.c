#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll>P;
#define MAX 1e15
struct edge{int to,cost;};
//_________________________________________________
ll V,E,r;
vector<P>G[100000];
ll d[100000];
bool used[100000];

int main() {
  cin >>V;
  cin >>E>>r;
  rep(i,V){d[i]=MAX; used[i]= false;}
  d[r]=0;
  //入力
  int a,b,c;//a→ｂのコストがｃ。
  for(int i=0;i<E;i++){
    cin >>a>>b>>c;
   	G[a].push_back(P(b,c));
  
  }
  
  
  
  priority_queue<P,vector<P>,greater<P>> PQ;
  PQ.push(P(0,r));//P(x,y)についてtyoutenｒからｙへの距離がｘである。
  while(!PQ.empty()){
   P f=PQ.top();PQ.pop();
    int u= f.second;
    used[u]=true;
    if(d[u]<f.first) continue;//すでにd[u]にあるやつのほうが小さいなら更新不要
    
    for(int j=0;j<G[u].size();j++){
     	int v=G[u][j].first;
      	if(used[v]){continue;}
      	if(d[v]>d[u]+G[u][j].second){d[v]=d[u]+G[u][j].second;
          PQ.push(P(d[v],v));
          
        }
    }  //forno
  } //whileno
  
  rep(i,V){
  if(d[i]!=MAX){cout<<d[i]<<endl;}
  else{cout<<"INF"<<endl;}
  
  }
  
}
