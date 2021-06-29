#include<stdio.h>
#include<stdlib.h>

#define N 100
#define GR 1
#define BL 2
#define WH 0

int n, M[N][N];
int tt, color[N], d[N], f[N];

void dfs_visit(int u){
    int aa;
    color[u] = GR;
    d[u] = ++tt;
    
    for(aa=0 ; aa<n ; aa++){
        if(M[u][aa] == 0){continue;}
        if(color[aa] == WH){dfs_visit(aa);}
    }
    
    color[u] = BL;
    f[u] = ++tt;
}

void dfs(){
    int u;
    
    for(u=0 ; u<n ; u++){color[u] = WH;}
    tt = 0; 
    
    for(u=0 ; u<n ; u++){
        if(color[u]==WH){dfs_visit(u);}
    }
    for(u=0 ; u<n ; u++){
        printf("%d %d %d\n", u+1, d[u], f[u]);
    }
}

int main(){
    int u, v, k, i, j;
    
    scanf("%d", &n);
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){M[i][j] = 0;}
    }
    
    for(i=0 ; i<n ; i++){
        scanf("%d %d", &u, &k);
        u--;
        for(j=0 ; j<k ; j++){
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }
    
    dfs();
    
    return 0;
}
