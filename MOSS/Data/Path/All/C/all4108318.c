#include <iostream>
#include<algorithm>
#define MAX 20000000000001
using namespace std;

int main() {
    int V, E, tmp_f, tmp_s ,tmp , k=0;
    cin >> V >> E;
    long long int A[V][V];
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            if (i==j) {
                A[i][j] = 0;
            } else {
                 A[i][j] = MAX;
            }
        }
    }
    for (int i=0; i<E; i++) {
        cin >> tmp_f >> tmp_s;
        cin >> tmp;
        A[tmp_f][tmp_s] = tmp;
    }
    for (int k=0; k<V; k++) {
        for (int i= 0; i<V; i++) {
            if(A[i][k] == MAX) continue;
            for (int j=0; j<V; j++) {
                if(A[k][j] == MAX) continue;
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    for (int i=0; i<V; i++) {
        if (A[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    
    
    for (int i=0; i<V; i++) {
        for (k=0; k<V; k++) {
            if (A[i][k] != MAX) {
                cout << A[i][k];
            } else {
                cout << "INF";
            }
            if (k == V-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}

