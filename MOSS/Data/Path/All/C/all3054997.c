#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int v, e;
vector<long long> d(200);
long long a[200][200];

void warshall() {
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            if(a[i][k] == INT_MAX) continue;
            for (int j = 0; j < v; ++j) {
                if(a[k][j] == INT_MAX) continue;
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }

        }
    }
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (i == j)
                a[i][j] == 0;
            else
                a[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < e; ++k) {
        int s,t,dd;
        cin >> s >> t>>dd;
        a[s][t] = dd;
    }
    warshall();

    bool flag = false;
    for (int l = 0; l < v; ++l) {
        if(a[l][l] < 0) flag = true;
    }
    if(flag) {
        cout << "NEGATIVE CYCLE" << endl; return 0;
    }
    for (int m = 0; m < v; ++m) {
        for (int i = 0; i < v; ++i) {
            if(i) cout << " ";
           if(a[m][i] == INT_MAX) cout << "INF" ;
           else
               cout << a[m][i];
        }

        cout << endl;
    }

    return 0;
}

