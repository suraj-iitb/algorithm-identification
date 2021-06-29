#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 INF = 1e13;

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<i64>> cost(v, vector<i64>(v, INF*2));
    for(int i=0;i<v;++i)cost[i][i] = 0;
    for(int i=0;i<e;++i){
        int s, t;
        i64 d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }

    for(int k=0;k<v;++k){
        for(int i=0;i<v;++i){
            for(int j=0;j<v;++j){
                if(cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    bool negative_loop = false;
    for(int i=0;i<v;++i){
        if(cost[i][i] < 0){
            negative_loop = true;
            break;
        }
    }
    if(negative_loop){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int i=0;i<v;++i){
            for(int j=0;j<v;++j){
                if(j)cout << " ";
                if(cost[i][j] < INF)cout << cost[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
    return 0;
}

