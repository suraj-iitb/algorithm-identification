#include <bits/stdc++.h>
using namespace std;
#define ll long long int

static const ll INF = (1LL << 32);
static const int MAX = 100;

ll n, d[MAX][MAX];

void warshall_floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(d[i][k] == INF) continue;
            for(int j=0; j<n; j++){
                if(d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int e;
    cin >> n >> e;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            d[i][j] = (i == j) ? 0 : INF;
        }
    }
    for(int i=0; i<e; i++){
        int s, t, c;
        cin >> s >> t >> c;
        d[s][t] = c;
    }
    warshall_floyd();
    bool neg = false;
    for(int i=0; i<n; i++) if(d[i][i] < 0) neg = true;
    if(neg) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j) cout << " ";
                if(d[i][j] == INF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

