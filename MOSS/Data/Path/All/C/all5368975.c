#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<tuple>
#include<iomanip>
#include<stdio.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using graph = vector<vector<int>>;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
using ll = long long;
using P = pair<int, int>;

int par[2000];
void inti(){
  rep(i,2000) par[i]=i;
}

int root(int x){
  if(x==par[x]) return x;
  else return par[x]=root(par[x]);
}

void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x==y) return;
  par[x] = y;
}

int main(){

    int v,e;cin >> v >> e;

    vector<vector<ll>> dist(v,vector<ll>(v,INF));

    rep(i,e){
      int a,b;
      ll c;
      cin >> a >> b >> c;
      dist[a][b] = c;
    //  dist[b][a] = c;
    }

//    graph dist(n,vector<int>(n,1e9));
    rep(i,v) dist[i][i] = 0;

    rep(k,v){
      rep(i,v){
        rep(j,v){
         if(dist[i][k]==INF||dist[k][j]==INF) continue;
          dist[i][j] = min(dist[i][k] + dist[k][j] , dist[i][j]);
        }
      }
    }

   rep(i,v){
     if(dist[i][i]<0){
       cout << "NEGATIVE CYCLE" << endl;
       return 0;
     }
   }

   rep(i,v){
      rep(j,v){
     if(j<v-1){
         if(dist[i][j]!=INF) cout << dist[i][j] << " ";
         else cout << "INF" << " ";
     }
     
     else{
         if(dist[i][j]!=INF) cout << dist[i][j] << endl;
         else cout << "INF" << endl;
     }
      }
   }


}

