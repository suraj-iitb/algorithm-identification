#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
#define INF (1LL<<32)

static int V, E;
long long A[MAX][MAX];

void warshall_floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (A[i][k]==INF) continue;
            for (int j = 0; j < V; j++) {
                if (A[k][j]==INF) continue;
                A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
            }
        }
    }
    return;
}

bool check_negative_cycle() {
    bool flag = false;
    for (int i = 0; i < V; i++) {
        if (A[i][i] < 0) flag = true;
    }
    return flag;
}

void print_distance(long long value) {
    if (value==INF) cout << "INF";
    else cout << value;
    return;
}

void print_distances() {
    if (check_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return;
    }
    for (int i = 0; i < V; i++) {
        print_distance(A[i][0]);
        for (int j = 1; j < V; j++) {
            cout << ' ';
            print_distance(A[i][j]);
        }
        cout << endl;
    }
    return;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) A[i][j] = ((i==j) ? 0 : INF);
    }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        A[s][t] = d;
    }

    warshall_floyd();
    print_distances();

    return 0;
}

