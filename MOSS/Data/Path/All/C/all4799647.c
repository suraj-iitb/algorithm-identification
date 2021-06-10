#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxv = 110;
ll cost[maxv][maxv];
ll d[maxv][maxv];
const ll INF = 0x3f3f3f3f3f3f3f3f;
bool negative_loop = false;
int V,E;

void floyd(){
    for(int k = 0;k<V;k++){
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(cost[i][k]!=INF && cost[k][j]!=INF){
                    cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
                }
            }
        }
    }
    for(int i = 0;i<V;i++){
        if(cost[i][i] < 0) negative_loop = true;
    }
}
int main(){
    cin >> V >> E;
    for(int i = 0;i<V;i++){
        for(int j = 0;j<V;j++){
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }
    for(int i = 0;i< E;i++){
        int f,t,c;
        scanf("%d%d%d",&f,&t,&c);
        cost[f][t] = c;
    }
    floyd();
    if(negative_loop){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(j == V-1){
                    if(cost[i][j] != INF) cout << cost[i][j];
                    else cout << "INF";
                }else{
                    if(cost[i][j] != INF) cout << cost[i][j] << " ";
                    else cout << "INF ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
