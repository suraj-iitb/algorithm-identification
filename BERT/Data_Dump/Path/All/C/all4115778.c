#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
 
static const int MAX =100;
static const int long long INF = (1LL << 32);

int g;
long long A[MAX][MAX];

void floyd() {
	for (int k= 0;k<g; k++) { 
		for (int i = 0; i<g ; i++) { 
	    if (A[i][k] == INF) continue;
				for (int j = 0; j<g ;j++) {
				    if(A[k][j] == INF) continue;
					A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				}
		}
	}
}



int main() {
    int v;
	cin >> g >> v;

	//初期化
	for (int i = 0; i< g ; i++) {
		for (int j = 0; j<g ;j++) {
		  if (i == j) A[i][j] = 0;
		  else A[i][j] = INF;
		}
	}

	//入力でわかったおもみを入れる
	for (int k = 0; k<v;k++) {
		int n, m, d;
		cin >> n >> m >> d;

		A[n][m] = d;
	}
	
	floyd();
	

    for (int l =0;l <g;l++) {
        if (A[l][l] <0 ){
            cout << "NEGATIVE CYCLE" << endl; 
            exit(0);
        }
    }

	for (int i = 0; i< g; i++) {
		for (int j = 0; j<g ;j++) {
		    if(j) cout << " ";
		    if(A[i][j] == INF) cout <<"INF";
			else cout << A[i][j];
		}
		cout << endl;
	}
	return 0;
}


