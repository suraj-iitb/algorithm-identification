#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int main(void){
	int v, e;
	cin >> v >> e;
	long leng[v][v];
	fill(leng[0], leng[v], INF);
	for(int i = 0; i < v; i++) leng[i][i] = 0;
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		leng[a][b] = (long)c;
	}
	for(int k = 0; k < v; k++){
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(leng[i][k] != INF && leng[k][j] != INF)
					leng[i][j] = min(leng[i][j], leng[i][k] + leng[k][j]);
			}
		}
	}
	int flg = 1;
	for(int i = 0; i < v; i++){
		if(leng[i][i] < 0){
			flg = 0;
			break;
		}
	}
	if(!flg) cout << "NEGATIVE CYCLE" << endl;
	else {
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v - 1; j++){
				if(leng[i][j] != INF) cout << leng[i][j] << ' ';
				else cout << "INF" << ' ';
			}
			if(leng[i][v - 1] != INF) cout << leng[i][v - 1] << endl;
			else cout << "INF" << endl;
		}
	}
	return 0;
}
