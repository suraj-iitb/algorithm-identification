#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX_V = 100;
const ll INF = (1LL << 32);

int v, e;
long long D[MAX_V][MAX_V];

void warshallFloyd(void) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            if (D[i][k] == INF) continue;
            for (int j = 0; j < v; j++) {
                if (D[k][j] == INF) continue;
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
    }
}

int main(void) {
    cin >> v >> e;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j) {
                D[i][j] = INF;
            } else {
                D[i][j] = 0;
            }
        }
    }

    int s, t, d;
    for (int i = 0; i < e; i++) {
        cin >> s >> t >> d;
        D[s][t] = d;
    }

    warshallFloyd();

    bool neg = false;
    for (int i = 0; i < v; i++) {
        if (D[i][i] < 0) neg = true;
    }

    if (neg) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (j) cout << " ";
                if (D[i][j] == INF) cout << "INF";
                else cout << D[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
