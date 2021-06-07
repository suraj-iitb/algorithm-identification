#include <stdio.h>
#include <stdlib.h>
#define N 102
#define BLACK 2
#define GRAY 1
#define WHITE 0

int n;
int color[N],M[N][N];
int stack[N],nt[N],tt;
int d[N],f[N];
int top = 0;

void push(int);
int pop (void);

void dfs(void);
void dfs_visit(int);
int next(int);

int main(){
    int u,k,v;
    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) M[i][j] = 0;
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v--;
            M[u][v] =1;
        }
    }

    dfs();

    return 0;
}

void push(int num){
  if (top == N) {
    /* スタックがいっぱいの場合、エラー処理を行う */
    printf("Stack overflow!\n");
    exit (2);
  }
  stack[top] = num;
  top++;
}

int pop(void){
  if (top == 0) {
    /* スタックが空の場合、エラー処理を行う */
    printf("Stack is empty!\n");
    exit (3);
  }
  top--;
  return stack[top];
}

void dfs(void){
    int i,u;
    for(i=0;i<n;i++){
        color[i] = WHITE;
        nt[i] = 0;
    }
    tt = 0;

    for(u=0;u<n;u++){
        if(color[u] == WHITE) dfs_visit(u);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}

void dfs_visit(int r){
    int i,u,v;
    for(i=0;i<n;i++) nt[i]=0;

    push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while( top != 0){
        u = stack[top-1];
        v = next(u);
        if( v != -1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v] = ++tt;
                push(v);
            }
        }
        else {
            pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}

int next(int u){
    int v;
    for(v = nt[u];v<n;v++){
        nt[u] = v+1;
        if( M[u][v] ) return v;
    }
    return -1;
}
