#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
typedef long long ll;

ll INF=1e18;
ll v, e, d[105][105], l[105];
bool flag = true;
struct edge { ll from, to, cost; };
edge es[10000];

void warshall_floyd() {
    for (int k = 0; k < v; k++) 
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++) {
                //if (i == 1 && j == 0) cout << d[i][j] << " " << d[i][k] << " " << d[k][j] << endl;
                if (d[i][j] != INF || d[i][k] != INF)
                if (d[i][j] != INF || d[k][j] != INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
            
}

bool find_negative_loop() {
    memset(l, 0, sizeof(l));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++) {
            edge e = es[j];
            if (l[e.to] > l[e.from] + e.cost) {
                l[e.to] = l[e.from] + e.cost;
                if (i == v - 1) return true;
            }
        }
    }
    return false;
}

int main(void){
    cin >> v >> e;
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j< v; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    
    for (int i = 0; i < e; i++) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
        d[es[i].from][es[i].to] = es[i].cost;
    }
    
    warshall_floyd();
    
    if (find_negative_loop()) cout << "NEGATIVE CYCLE" << endl;
    else 
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v - 1; j++) {
            if (d[i][j] != INF) cout << d[i][j] << " ";
            else cout << "INF ";
        }
        if (d[i][v - 1] != INF) cout << d[i][v - 1];
        else cout << "INF";
        
        cout << endl;
    }
    
}

