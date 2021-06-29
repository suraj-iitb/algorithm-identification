#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back
#define MAX 100


static const int WHITE = 0;
static const int GRAY =  1;
static const int BLACK = 2;
static const long long INFTY = (1LL<<32);
int n;
long long d[MAX][MAX];


  //PQ???(cost,node)????????§
  //nodes???(node,cost)??????????????£??????

void Floyd(){
  rep(k,n){
    rep(i,n){
      if(d[i][k]==INFTY) continue;
      rep(j,n){
        if(d[k][j] == INFTY) continue;
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
}

int main (void) {
  int e,u,v,c;
  cin >> n >> e;

  rep(i,n){
    rep(j,n){
      d[i][j] = ( (i==j) ? 0 : INFTY );
    }
  }

  rep(i,e){
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  Floyd();

  bool negative = false;
  rep(i,n) if(d[i][i] < 0) negative = true;

  if( negative ){
    cout << "NEGATIVE CYCLE" <<endl;
  }else{
    rep(i,n){
      rep(j,n){
        if (j) cout << " ";
        if ( d[i][j] == INFTY ) cout << "INF" ;
        else cout << d[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
