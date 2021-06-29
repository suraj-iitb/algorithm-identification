#include<iostream>
#define INF 999999999999
using namespace std;

long long map[210][211];
int n;

int floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (map[i][k] == INF){
			    continue;
			}
			for (int j = 0; j < n; j++) {
				if (map[k][j] == INF){
				    continue;
				}
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	return 0;
}
int main() {
	int m;
	cin >> n >> m;
	int a, b;
	long long c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++){
	    map[i][i] = 0;
	}
	while (m--) {
		cin >> a >> b >> c;
		if (map[a][b] > c){
		    map[a][b] = c;
		}
	}
	floyd();
	bool flag = false;
	for (int i = 0; i < n; i++){
	    if (map[i][i] < 0){
	        flag = true;
	    }
	}
	if (flag){
	    cout << "NEGATIVE CYCLE" << endl;
	}
	else{
	    for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
			    if (map[i][j] == INF){
			        cout << "INF";
			    }
			    else{
			        cout << map[i][j];
			    }
			    if (j != n - 1){
			        cout << " ";
			    }
		    }
		    cout << endl;
	    }
	}
	return 0;
}

