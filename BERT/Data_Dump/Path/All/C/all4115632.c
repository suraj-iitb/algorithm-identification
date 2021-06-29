#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
//#include<climits>
#define MAX 10000
#define NEG -10000

using namespace std;
static const long long INFTY = (1LL<<32);

long long path[MAX][MAX];//最小経路
int V;

void Floyd(){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            if(path[i][k] == INFTY){
                continue;
            }
            for(int j=0; j<V; j++){
                if(path[k][j] == INFTY){
                    continue;
                }
                
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
}

int main(){
    int E;
    int s, t, d;
    long long neg[MAX];
    
    cin >> V;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j){
                path[i][j] =0;
            }else{
                path[i][j] = INFTY;
                neg[i] = INFTY;
            }
                
        }
    }
    
    
    cin >> E;
    for(int i=0; i<E; i++){
        cin >> s >> t >> d;
        path[s][t] = d;
    }
    
    Floyd();
    
    
    bool Neg = false;
    for(int i=0; i<V; i++){
        if(path[i][i] < 0){
            //neg[i] = NEG;
            Neg = true;
        }
    }
        //for(int i=0; i<V; i++){
            
        //}
    
    if(Neg){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                if(path[j][k] == INFTY){
                    if(k != 0) cout << " ";
                    cout << "INF";
                }else{
                    if(k != 0) cout << " ";
                    cout << path[j][k];
                }
            }
            cout << endl;
        }
                    
    }
    
    return 0;
}


