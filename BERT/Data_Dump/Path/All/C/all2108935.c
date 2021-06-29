#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 110;
const long long int INF = 1e10;
long long int d[MAX][MAX];
int V;
void warshall_floyd() {
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main() {
	int E,s,t;
	long long int a,b=0;
	cin >> V >> E;
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 110; j++)
			d[i][j] = INF;
	for (int i = 0; i < 110; i++)d[i][i] = 0;
	for (int i=0; i < E; i++) {
		cin >> s >> t >> a;
		d[s][t] = a;
	}
	warshall_floyd(); 
	for (int i = 0; i < V; i++) {
		if (d[i][i] != 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i = 0; i < V; i++) {
		
	
		for (int j = 0; j < V; j++) {
			if (d[i][j] >= 5*1e9) {
				if (j!=0)cout << " ";
				cout << "INF";
			}
			else {
				if (j!=0)cout << " ";
				cout << d[i][j] ;
			}
		}
		cout << endl;
	}
	return 0;
}
