#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
using namespace std;

int inf = 2001001000;
void WF(vector<vector<int>> &graph){
	int n = graph.size();
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (graph[i][k] == inf || graph[k][j] == inf) graph[i][j] = min(graph[i][j], inf);
				else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}


int main(){
	int v, e; cin >> v >> e;
	vector<vector<int>> graph(v,vector<int>(v,inf));
	for (int i=0;i<e;i++){
		int s,t,d; cin >> s >> t >> d;
		graph[s][t] = d;
	}
	for (int i=0;i<v;i++) graph[i][i] = 0;
	WF(graph);
	for (int i=0;i<v;i++) {
		if(graph[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i=0;i<v;i++){
		for(int j = 0;j < v;j++){
			if (j != v - 1) {
				if (graph[i][j] == inf) cout << "INF" << " ";
				else cout << graph[i][j] << " ";
			} else {
				if (graph[i][j] == inf) cout << "INF" << endl;
				else cout << graph[i][j] << endl;
			}
		}
	}


	return 0;
}


