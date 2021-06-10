#include <bits/stdc++.h>
using namespace std;

#define INF INT32_MAX

int main()
{
	int V, E;
	cin >> V >> E;
	vector<vector<long long>> mat( V, vector<long long>( V, INF ) );
	for( int i = 0; i < V; i++ ) mat[i][i] = 0;
	for( int i = 0; i < E; i++ ) {
		int s, t, d;
		cin >> s >> t >> d;
		mat[s][t] = d;
	}

	for( int k = 0; k < V; k++ ) {
		for( int i = 0; i < V; i++ ) {
			if( mat[i][k] == INF ) continue;
			for( int j = 0; j < V; j++ ) {
				if( mat[k][j] == INF ) continue;
				mat[i][j] = min( mat[i][j], mat[i][k] + mat[k][j] );
			}
		}
	}
	int nega = 0;
	for( int i = 0; i < V; i++ ) {
		if( mat[i][i] < 0 ) {
			nega = 1;
			break;
		}
	}
	if( nega ) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for( int i = 0; i < V; i++ ) {
			for( int j = 0; j < V; j++ ) {
				if( j ) cout << " ";
				int d = mat[i][j];
				if( d == INF ) cout << "INF";
				else cout << d;
			}
			cout << endl;
		}
	}
}

