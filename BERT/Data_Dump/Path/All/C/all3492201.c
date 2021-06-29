#include <iostream>
#include <algorithm>

using namespace std;

int V, E, S, T;
long long D;
long long int M[100][100];
static const int INF = 2000000000;


int main(void){
    // Your code here!
    cin >> V >> E;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++){
            if(i == j) M[i][j] = 0;
            else M[i][j] = INF;
        }
    }
    
    for(int i = 0; i < E; i++){
        cin >> S >> T >> D;
        M[S][T] = D;
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            if(M[i][k] == INF) continue;
            for(int j = 0; j < V; j++){
                if(M[k][j] == INF) continue;
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }
    
    bool flag = true;
    for(int i = 0; i < V; i++){
        if(M[i][i] < 0){
            flag = false;
            break;
        }
    }
    
    if(!flag) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    for(int i = 0; i < V; i++){
        if(M[i][0] == INF) cout << "INF";
        else cout << M[i][0];
        
        for(int j = 1; j < V; j++){
            if(M[i][j] == INF) cout << " INF";
            else cout << " " << M[i][j];
        }
        
        cout << endl;
    }
    
  
    return 0;
    
}

