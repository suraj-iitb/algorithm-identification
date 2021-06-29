# if 0
15分ほど時間がかかった。
そこまで難しくはなかった。
# endif

#include <iostream>
using namespace std;

int V, E, R, S[500010], T[500010], D[500010]; // 問題で与えられる入力
int C[100010]; // 各頂点までの最短距離の上限
 // 無限を表す定数を全頂点をたどる最大超に設定
const int Inf = 10000*100000+100;

int main() {
  cin >> V >> E >> R;
  for (int i=0; i<E; ++i)
    cin >> S[i] >> T[i] >> D[i]; // 各辺を入力
  for (int i=0; i<V; i++) {
    if (i == R) {
      C[i] = 0;
    } else {
      C[i] = Inf;
    }
  }

  for (int t=0; t<V; ++t) { // V 回繰り返す
    bool update = false;
    for (int i=0; i<E; ++i) {
      int s = S[i], t = T[i], d = D[i]; // i 番目の辺の s,t,d に対して
      if (C[s] < Inf && C[t] > C[s] + d) { // 辺 s,t で緩和できるなら
        C[t] = C[s] + d;
        update = true; // 更新が起こったことを記録
      }
    } 
    if (!update) break; // 辺を一巡して更新がなければ打ち切って良い
  }
  for (int i=0; i<V; i++) {
    if (C[i] == Inf) {
      cout << "INF" << endl;
    } else {
     cout << C[i] << endl; 
    }
  }
}
