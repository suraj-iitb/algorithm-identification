#include<stdio.h>
int n,time; 
int A[100][100];
int d[101], f[101];

void visit(int u){
    int v;
    d[u]=++time;

    for(v=0; v<n; v++){
        if(A[u][v]&&d[v]==0){
            visit(v);
        }
    }
    f[u]=++time;
}
int main(void){

    int u,k,v; //u:頂点番号/k:出次数 v:隣接頂点
    time=0;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        d[i]=0;
        f[i]=0;
        for(int j=0; j<n; j++){
            A[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        scanf("%d %d",&u,&k);
        for(int j=0; j<k; j++){
            scanf("%d",&v);
            A[u-1][v-1]=1;
        }
    }
    for(int i=0; i<n; i++){
        if(d[i]==0){
            visit(i);
        }
    }
    for(int i=0; i<n; i++){
        printf("%d %d %d\n",i+1, d[i], f[i]);
    }
    return 0;
}
