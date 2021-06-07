#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[100][100],color[100],d[100],f[100],t;
void depthA(int);
void depthB(void);

int main(){
    int i,j,a,b,c;
    
    scanf("%d",&n);
    
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            M[i][j] = 0;
        }
    }
    for(i = 0;i < n;i++){
        scanf("%d%d",&a,&b);
        a--;
        for(j = 0;j < b;j++){
            scanf("%d",&c);
            c--;
            M[a][c] = 1;
        }
    }
    depthB();
    return 0;
}

void depthA(int u){
    int i;
    
    color[u] = GRAY;
    d[u] =++t;
    
    for(i = 0;i < n;i++){
        if(M[u][i] == 0) continue;
        if(color[i] == WHITE){
            depthA(i);
        }
    }
    color[u] = BLACK;
    f[u] =++t;
}

void depthB(){
    int i;
    
    for(i = 0;i < n;i++) color[i] = WHITE;
    t = 0;
    for(i = 0;i < n;i++){
        if(color[i] == WHITE) depthA(i);
    }
    for(i = 0;i < n;i++){
        printf("%d %d %d\n",i + 1,d[i],f[i]);
    }
}
