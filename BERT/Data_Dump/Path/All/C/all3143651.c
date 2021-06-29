#include<bits/stdc++.h>
using namespace std;

static const int MAX = 100;
static const long long INFTY = (1LL<<32);

int V;
long long d[MAX][MAX];

void floyd(){
  // i->jの際に経由させるNode Number
  for(int k=0;k<V;k++){

    for(int i=0;i<V;i++){
      // i->kのパスがなければcontinue
      if(d[i][k] == INFTY) continue;

      for(int j=0;j<V;j++){
        //k->jのパスがなければcontinue
        if(d[k][j] == INFTY) continue;
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
  int E,s,t,cost;
  cin >> V >> E;

  // 初期化 s=t,s->tのコストは0
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      d[i][j] = ((i == j) ? 0 : INFTY);
    }
  }

  // s -> t コスト入力
  for(int i=0;i<E;i++){
    cin >> s >> t >> cost;
    d[s][t] = cost;
  }

  floyd();

  bool negative = false;
  for(int i=0;i<V;i++) if(d[i][i] < 0) negative = true;

  // output
  if(negative){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        if(j) cout << " ";
        if(d[i][j] == INFTY) cout << "INF";
        else cout << d[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}

