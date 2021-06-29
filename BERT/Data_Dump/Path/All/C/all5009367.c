#include <iostream>

#define NIL 10000000000000
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    long a[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) a[i][j] = 0;
            else a[i][j] = NIL;
        }
    }
   
    for(int i = 0; i < e; i++) {
        long s, t, d;
        cin >> s >> t >> d;
        a[s][t] = d; 
    }

    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if((a[i][k] != NIL) && (a[k][j] != NIL)) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(a[i][j] + a[j][i] < 0) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(a[i][j] == NIL) cout << "INF";
            else cout << a[i][j];
            if(j != v-1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}

