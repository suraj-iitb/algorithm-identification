#include <iostream>
#include <cstdio>
using namespace std;


int V, E, R, S[500010], T[500010], D[500010]; // 問題で与えられる入力
int C[100010]; // 各頂点までの最短距離の上限
// 無限を表す定数を全頂点をたどる最大超に設定
const int Inf = 10000*100000+100;

int main() {
  cin >> V >> E >> R;
  for (int i=0; i<E; i++){
    cin >> S[i] >> T[i] >> D[i]; // 各辺を入力
  }
  for (int i = 0; i < 100010; i++) C[i] = Inf;
  C[R] = 0;

    for (int t=0; t<V; t++) { // V回繰り返す
      bool update = false;
      for (int i=0; i<E; ++i) {
        int s = S[i], t = T[i], d = D[i]; // i番目の辺のs,t,dに対して
          if (C[s] < Inf && C[t] > C[s] + d) { // 辺s,tで緩和できるなら
          C[t] = C[s] + d;// C[t]を更新;
          update = true; // 更新が起こったことを記録
          }
        }
        if (!update) break;
    }

    for (int i = 0; i < V; i++){
      if (C[i] == Inf){
        cout << "INF" << endl;
      }else{
        cout << C[i] << endl;
      }
    }
    return 0;
  }

