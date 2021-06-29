#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 100000000000000000
using namespace std;

int main(){
	int V,E,r;
	cin >> V >> E;
	long long int d[V][V] = {};
	for(int i = 0;i < V;i++) {
		for(int j = 0;j < V;j++) d[i][j] = INF;
		d[i][i] = 0;
	}
	for(int i = 0;i < E;i++){
		int a,b,c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	for(int k = 0;k < V;k++){
		for(int i = 0;i < V;i++){
			for(int j = 0;j < V;j++) {
				if(d[i][k] != INF && d[k][j] != INF) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	for(int i = 0;i < V;i++) {
		if(d[i][i] < 0){
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for(int i = 0;i < V;i++) {
		if(d[i][0] == INF) cout << "INF";
		else cout << d[i][0];
		for(int j = 1;j < V;j++){
			if(d[i][j] == INF) cout << " INF";
			else cout << " " << d[i][j];
		}
		cout << endl;
	}
	return 0;
}
