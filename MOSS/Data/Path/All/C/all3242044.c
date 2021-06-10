#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

vector<vector<ll>> dist(1010,vector<ll>(1010,1e18));

void Warshall_floyd(int& V){
    for(int mid=0;mid<V;++mid){
        for(int s=0;s<V;++s){
            for(int e=0;e<V;++e){
                if(dist[s][mid] == 1e18 || dist[mid][e] == 1e18) continue;
                dist[s][e] = min(dist[s][e],dist[s][mid] + dist[mid][e]);
            }
        }
    } 
}

int main(){
    int V,E;
    cin >> V >> E;
    for(int i=0;i<E;++i){
        int s,t,d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    for(int i=0;i<V;++i) dist[i][i] = 0;
    Warshall_floyd(V);

    for(int i=0;i<V;++i){
        if(dist[i][i] < 0){
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            if(dist[i][j] >= 1e18) cout << "INF";
            else cout << dist[i][j];
            if(j != V-1) cout << " ";
        }
        cout << endl;
    }
}
