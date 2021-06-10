#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

static const long long INFTY = (1LL<<32);

int n;
long long d[100][100];

void warshall_floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(d[i][k] == INFTY) continue;
            for(int j = 0; j < n; j++){
                if(d[k][j] == INFTY) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int E, u, v, c;
    cin >> n >> E;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = ((i == j) ? 0 : INFTY);
        }
    }
    for(int i = 0; i < E; i++){
        cin >> u >> v >> c;
        d[u][v] = c;
    }
    
    warshall_floyd();
    
    bool negative = 0;
    for(int i = 0; i < n; i++){
        if(d[i][i] < 0) negative = 1; //閉路がマイナスだったら
    }
    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j != 0) cout << " ";
                if(d[i][j] == INFTY) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
    
}
