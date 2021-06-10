#include <iostream>
#include<cstdio>
using namespace std;
#define MAX 100
long long A[MAX][MAX];
long long  INF = 1LL << 32;

void warshallFloyd(int v){
    for(int k = 0;k < v;++k){
        for(int i = 0;i < v;++i){
            if(A[i][k] == INF) continue;
            for(int j = 0;j < v;++j){
                if(A[k][j] == INF) continue;
                A[i][j] = min(A[i][j],A[i][k] + A[k][j]);
            }
        }
    }
}
int main(void){
    int v,e,s,t,d;
    for(int i = 0;i < MAX;++i){
        for(int j = 0;j < MAX;++j){
            A[i][j] = (i == j) ? 0:INF;
        }
    }
    scanf("%d %d",&v,&e);
    for(int i = 0;i < e;++i){
        scanf("%d %d %d",&s,&t,&d);
        A[s][t] = d;
    }
    warshallFloyd(v);
    for(int i = 0;i < v;++i){
        if((A[i][i] < 0)){
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }
    for(int i = 0;i < v;++i){
        for(int j = 0;j < v;++j){
            if((A[i][j] != INF)){
                printf((j != v-1) ? "%lld " : "%lld",A[i][j]);
            } else{
                printf((j != v-1) ?"INF ":"INF");
            }
        }
        printf("\n");
    }
    
}


