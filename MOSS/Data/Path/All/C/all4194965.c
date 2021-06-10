#include <bits/stdc++.h>

using namespace std;
#define INF 1e10

void warshallFloyd(vector<vector<long> > &min_d,
                   const int &V,
                   const int &E)
{
    for(int k = 0; k < V;k++){
        for(int i = 0;i < V;i++){
            if(min_d[i][k] == INF) continue; // 計算の節約（無駄にループ回さない）
            for(int j = 0;j < V;j++){
                if(min_d[k][j] == INF) continue; // 計算の節約（無駄にループ回さない）
                min_d[i][j] = min(min_d[i][j],min_d[i][k] + min_d[k][j]);
            }
        }
    }
}

int main()
{
    // ----- Input ----- //
    int V,E;
    int s,t;
    long d;
    cin >> V >> E;
    vector<vector<long> > min_d(V,vector<long>(V,INF) );
    
    for(int i = 0;i < E;i++){
        cin >> s >> t >> d;
        min_d[s][t] = d;
    }
    for(int i = 0;i < V;i++) min_d[i][i] = 0;

    warshallFloyd(min_d,V,E);
    bool is_negative_cycle = false;

    for(int i = 0;i < V;i++){
        if(min_d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << "\n";
            is_negative_cycle = true;
            break;
        }    
    }
    if(is_negative_cycle == false){
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V-1;j++){
                if(min_d[i][j] == INF) cout << "INF" << " ";
                else cout << min_d[i][j] << " ";
            }
            if(min_d[i][V-1] == INF) cout << "INF" << "\n";
            else cout << min_d[i][V-1] << "\n";
        }
    }
    


    return 0;
}


