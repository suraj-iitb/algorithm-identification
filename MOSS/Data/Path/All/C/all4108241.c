#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 100
#define INF 1LL << 32
using namespace std;

int V;
long long D[MAX][MAX];

void warshallFloyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            if(D[i][k] == INF) continue;
            for(int j = 0; j < V; j++){
                if(D[k][j] == INF) continue;
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
}
int main(){
    int E, s, t, d;
    scanf("%d %d",&V,&E);
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if( i == j) D[i][j] = 0;
            else D[i][j] = INF;
        }
    }
    
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &s, &t, &d);
        D[s][t] = d;
    }
    
    warshallFloyd();
    int flag = 1;
    for(int i = 0; i < V; i++){
        if(D[i][i] < 0) flag = 0;
    }
    
    if(flag == 0) printf("NEGATIVE CYCLE\n");
    else{
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(j != 0) cout << " ";
                if (D[i][j] == INF) cout << "INF";
                else cout << D[i][j];
                
            }
            cout << endl;
        }
    }
    return 0;
    
}
