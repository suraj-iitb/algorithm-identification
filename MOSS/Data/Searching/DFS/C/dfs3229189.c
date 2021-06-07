#include <stdio.h>
 
#define N 100
enum {
    WHITE,
    GRAY,
    DARK
};
 
int M[N][N] = {0};
int color[N] = {0};
int dt[N] = {0};
int ft[N] = {0}; 
int tt = 0, n = 0;
 
void dfs_visit(int u){
    int v;
    color[u] = GRAY;
    dt[u] = ++tt;
    for(v = 0; v < n; v++){
        if(M[u][v] == 0) continue;
        if(color[v] == WHITE){
            dfs_visit(v);
        }
    }
        color[u] = DARK;
        ft[u] = ++tt;
}
 
void dfs(){
    int i;
    for(i = 0; i < n; i++){
        if(color[i] == WHITE){
            dfs_visit(i);
        }
    }
 
    for(i = 0; i < n; i++){
        printf("%d %d %d\n", i+1, dt[i], ft[i]);
    }
}
 
int main(void){
     
    int u, k, v, i, j;
    u = k = v = 0;
 
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
            scanf("%d", &u);
            scanf("%d", &k);
            for(j = 0; j < k; j++){
                scanf("%d", &v);
                v--;
                M[i][v] = 1;
            }   
    }
      
    dfs();
 
}
