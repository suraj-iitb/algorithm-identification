/*
	ワーシャル-フロイド法(無向グラフ)
										*/

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1L<<60;

long long V, E;
vector<vector<long long>> d;
struct Edge {
	long long from;
	long long to;
	long long cost;
};

vector<Edge> es;
vector<long long> d2;

void warshall_floyd(){
	for(long long k = 0; k < V; k++){
		for(long long i = 0; i < V; i++){
			for(long long j = 0; j < V; j++){
				if(i == j){
					d[i][j] = 0;
				}else{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}

bool find_negative_loop() {
	for(long long i = 0; i < V; i++) d2[i] = 0;
	for(long long i = 0; i < V; i++){
		for(long long j = 0; j < E; j++){
			Edge e = es[j];
			if(d2[e.to] > d2[e.from] + e.cost){
				d2[e.to] = d2[e.from] + e.cost;
				if(i == V - 1) return true;
			}
		}
	}
	return false;
}

int solve() {
	cin >> V >> E;
	d2.resize(V);
	d.resize(V, vector<long long>(V));
	for(long long i = 0; i < V; i++){
		for(long long j = 0; j < V; j++){
			d[i][j] = INF;
		}
	}
	for(long long i = 0; i < E; i++) {
		long long a, b, cost;
		cin >> a >> b >> cost;
		Edge e = {a, b, cost};
		es.push_back(e);
		d[a][b] = cost;
	}
	if(find_negative_loop()){
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	warshall_floyd();
	for(long long i = 0; i < V; i++){
		for(long long j = 0; j < V; j++){
			if(d[i][j] >= INF - 1000000000000){
				if(j == V-1){
					cout << "INF";
				}else{
					cout << "INF" << " ";
				}
			}else{
				if(j == V-1){
					cout << d[i][j];
				}else{
					cout << d[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}

int main() {
	cout << std::fixed << std::setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return solve();
}

