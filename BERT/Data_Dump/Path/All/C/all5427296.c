#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
static const long long INF = LLONG_MAX;

void warshallFloyd(vector<vector<long long> > &A) {
    int n = A.size();
    for ( int k = 0; k < n; k++ ) {
        for ( int i = 0; i < n; i++ ) {
            if ( A[i][k] == INF ) { continue; }
            for ( int j = 0; j < n; j++ ) {
                if ( A[k][j] == INF ) { continue;}
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
}

int main() {
    int n, e;
    int u, v, c;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> e;
    vector<vector<long long> > A(n, vector<long long>(n));
    //初期化
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            A[i][j] = ( ( i == j ) ? 0 : INF );
        }
    }
    for ( int i = 0; i < e; i++ ) {
        cin >> u >> v >> c;
        A[u][v] = c;
    }

    warshallFloyd(A);

    bool isNegative = false;
    // 負のサイクルがあるか判定
    for ( int i = 0; i < n; i++ ) { 
        if ( A[i][i] < 0 ) {
            isNegative = true;
            break;
        }
    }

    if ( isNegative ) { cout << "NEGATIVE CYCLE\n"; } 
    else {
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( j >= 1 ) { cout << " "; }
                if ( A[i][j] == INF ) { cout << "INF"; }
                else { cout << A[i][j]; }
            }
            cout << "\n";
        }
    }

    return 0;
}


