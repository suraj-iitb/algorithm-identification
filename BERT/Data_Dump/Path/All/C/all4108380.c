#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

static const long long INFTY = (1LL<<32);
int egs[9900];
int N[100];
int v, e;
long long D[100][100];

void floyd() {
	for (int k = 0;k < v ;k++) {
		for (int i = 0;i < v;i++) {
			if (D[i][k] == INFTY) continue;
			for (int j = 0;j < v ;j++) {
				if (D[k][j] == INFTY) continue;
				D[i][j]=min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}
int main() {
	int s, t, d;
	cin >> v >> e;
	
	for (int i = 0;i <v;i++) {
		for (int j = 0;j < v;j++) {
			if (i == j) { D[i][j] = 0; }
			else { D[i][j] = INFTY; }
		}
	}
	for (int i = 0;i < e;i++) {
		cin >> s >> t>> d;
		D[s][t] = d;
	}
	floyd();
	for (int i = 0;i < v;i++) {
		if (D[i][i] < 0) {
			cout<< "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i =0;i < v ;i++) {
		for (int j = 0;j < v;j++) {
		    if(j)cout<<" ";
			if (D[i][j] == INFTY) {
				cout << "INF";
			}
			else {
				cout << D[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
