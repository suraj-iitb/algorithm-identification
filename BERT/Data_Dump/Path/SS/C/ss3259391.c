#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V, E, r;
int S[500050],T[500050], D[500050];

int C[100010]; // 各頂点までの最短距離の上限
// 無限を表す定数を全頂点をたどる最大超に設定
const int Inf = 10000*100000+100;
//vector<pair<int, int>> w;

void bellman_ford(int V, int E, int D[], int r){
	
	for(int i = 0; i <= V; ++i){
		C[i] = Inf;
		C[r] = 0;
		//cout << C[i] << endl;
	}
	//cout << r << endl;
	//cout << C[0] << " " << C[1] << " "<< C[2] <<   endl;
	for (int t=0; t<V; ++t){
		bool update = false;
		for (int i=0; i<E; ++i){

			int s = S[i], t = T[i], d = D[i]; // i 番目の辺のs,t,d に対して
			//cout << C[s] << " " << C[t] << endl;
			if(C[s] < Inf && C[t] > C[s] + d){//s,tを緩和できるならば
				C[t] = C[s] + d; //C[t]を更新
				update = true;	
			} 
		}
		if (!update) break;
	}
	for (int t=0; t<V; ++t){
		if(C[t] != Inf){
			cout <<  C[t] << endl;
		}
		else{
			cout << "INF" << endl;
		}
	}	
}

int main(){
	cin >> V >> E >> r;
	for(int i = 0; i < E; ++i){
		cin >> S[i] >> T[i] >> D[i];
	}
	bellman_ford(V, E, D, r);
}
