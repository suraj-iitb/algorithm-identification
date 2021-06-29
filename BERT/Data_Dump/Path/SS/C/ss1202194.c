#include <iostream>
using namespace std;

int V,E,R,S[500010],T[500010],D[500010]; //問題で与えられる入力
int C[100000]; //各頂点までの最短距離の上限
//無限を表す定数を全頂点をたどる最大超に設定
const int Inf = 10000*100000+100;

int main(){
  for (int i = 0; i < 100000; i++){
   C[i] = Inf;
   }
  cin >> V >> E >> R;
  C[R] = 0;
  for (int i=0; i<E; i++){
    cin >> S[i] >> T[i] >> D[i]; //各辺を入力
	//Cを初期化:C[R]を0に、他をInfに
	}
	for (int t=0; t<V; ++t) { //V回繰り返す
	  bool update = false;
	  for (int i = 0; i<E; ++i) {
	    int s = S[i], t = T[i], d = D[i]; //i番目の辺のs,t,dに対して
		if (C[s] < Inf && C[t] > C[s] + d) { //辺s,tで緩和できるなら
		  C[t] = C[s] + d;//C[t]を更新
		  update = true; //更新が起こったことを記録
		  }
		 }
		if (!update) break; //辺を一巡して更新がなければ打ち切ってよい
		}
	   for (int j=0; j < V; j++){
	    if (C[j] < Inf){
	    cout << C[j] << endl;
		}
		else {
		cout << "INF" << endl;
		}
	  }
	}
