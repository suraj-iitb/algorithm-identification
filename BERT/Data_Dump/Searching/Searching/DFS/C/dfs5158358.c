#include <stdio.h>

#define MAX 101
#define NIL -1

typedef struct{
    int u;
    int s;
    int f;
}gve;

void visit(int);


int stack[MAX], top=1, time=0, n, adj[MAX][MAX];
gve sv[MAX];



int main(){
    int i, j, u, k, v;
    //input
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            adj[i][j]=0;
        }
        sv[i].s=NIL;
        sv[i].f=NIL;
        sv[i].u=NIL;
    }
    for(i=1; i<=n; i++){
        scanf("%d%d", &u, &k);
        for(j=0; j<k; j++){
            scanf("%d", &v);
            adj[u][v]=1;
        }
    }
    //
    for(i=1; i<=n; i++){
        if(sv[i].u!=1){
            visit(i);
        }
    }
    //output
    for(i=1; i<=n; i++){
        printf("%d %d %d\n", i, sv[i].s, sv[i].f);
    }
    return 0;
}

// void push(int i){
//     top++;
//     stack[top]=i;
// }

// int pop(){
//     top--;
//     if(top==0){
//         return NIL;
//     }
//     return stack[top+1];
// }


void visit(int u){
    int i;
    sv[u].u=1;
    sv[u].s=++time;
    for(i=1; i<=n; i++){
        if(adj[u][i]==1&&sv[i].u!=1){
            visit(i);
        }
    }
    sv[u].f=++time;
}
