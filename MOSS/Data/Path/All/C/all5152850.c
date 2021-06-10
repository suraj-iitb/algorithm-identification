#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 1e18
int main(){
	int V, E;
	cin >> V >> E;
	long long int s,t,d;
	vector<vector<long long int> > D(V,vector<long long int>(V,INT_MAX));
	for(int i=0;i<V;i++){
		D[i][i] = 0;
	}
	for(int i=0;i<E;i++){
		cin >> s >> t >> d;
		D[s][t] = d;
		}
	bool flg = true;
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
				if(D[i][i] < 0) {
					flg = false;
					break;
					}
				}
			}
		}
	if(flg){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(D[i][j] >= 1e10) cout << "INF";
			else cout << D[i][j];
			if(j==V-1) cout << "\n";
			else cout << " ";
			}
		}
	}
	else cout << "NEGATIVE CYCLE\n";
	}

