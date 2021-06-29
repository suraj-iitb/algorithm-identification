#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1001001001001001;

int main() {
    int V,E;
    cin >> V >> E;
    vector<long long> a(V,INF);
    vector< vector<long long> > d(V,a);
    for(int i=0; i<V; i++) d[i][i] = 0;
    for(int i=0; i<E; i++) {
        long long s,t,w;
        cin >> s >> t >> w;
        d[s][t] = w;
    }

    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for(int i=0; i<V; i++) {
        if(d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for(int i=0; i<V; i++) {
        for(int j=0; j<V-1; j++) {
            if(d[i][j] == INF) cout << "INF ";
            else cout << d[i][j] << " "; 
        }
        if(d[i][V-1] == INF) cout << "INF" << endl;
        else cout << d[i][V-1] << endl;
    }
    return 0;
}
