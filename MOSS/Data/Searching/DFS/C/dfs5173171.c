#include <stdio.h>
#define N 100
#define white 0
#define gray 1
#define black 2
int A[N][N],color[N], d[N], f[N], time,n;

void visit_dfs(int x){

    int i;
    color[x] = gray;
    d[x] = ++time;
    for(i=0; i<n; i++){
        if(A[x][i] == 0) continue;
        if(color[i] == white) visit_dfs(i);
    }
    color[x] = black;
    f[x] = ++time;
}

void dfs(){
    int i;
    for(i=0; i<n; i++) color[i] = white;
    time = 0;
    for(i=0; i<n; i++){
        if(color[i] == white) visit_dfs(i);
    }
    for(i=0; i<n; i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }

}

int main () {
    int a,b,c,i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j] = 0;
        }
    }
    for(i=0; i<n; i++){
        scanf("%d %d",&a,&c);
        a--;
        for(j=0;j<c; j++){
            scanf("%d",&b);
            b--;
            A[a][b] = 1;
        }
    }
    dfs();

    return 0;
}
