#include<bits/stdc++.h>
using namespace std;

constexpr long long INF = 1LL << 61;

// cost:=全頂点対の最短経路長がここに書き込まれる
// 負閉路が存在する場合はfalse, それ以外の場合はtrueを返す
bool warshall_floyd(vector< vector<long long> >& cost){
    const int v = (int)cost.size();
 
    for(int k = 0 ; k < v ; ++k){
        for(int i = 0 ; i < v ; ++i){
            for(int j = 0 ; j < v ; ++j){
                if(cost[i][k] < INF && cost[k][j] < INF){
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    for(int i = 0 ; i < v ; ++i){
        if(cost[i][i] < 0LL){
            return false;
        }
    }

    return true;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector< vector<long long> > cost(v, vector<long long>(v, INF));
    for(int i = 0 ; i < v ; ++i){
        cost[i][i] = 0;
    }

    for(int i = 0 ; i < e ; ++i){
        int s, t;
        long long d;
        cin >> s >> t >> d;
        cost[s][t] = min(cost[s][t], d);
    }

    if(warshall_floyd(cost)){
        for(int i = 0 ; i < v ; ++i){
            for(int j = 0 ; j < v ; ++j){
                if(j) cout << ' ';
                if(cost[i][j] < INF){
                    cout << cost[i][j];
                }else{
                    cout << "INF";
                }
            }
            cout << endl;
        }
    }else{
        cout << "NEGATIVE CYCLE" << endl;
    }

    return 0;
}
