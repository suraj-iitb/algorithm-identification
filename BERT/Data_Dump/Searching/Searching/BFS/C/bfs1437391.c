#include<stdio.h>

int n, G[110][110], d[110], Q[110], c[110];
int t = 0, h, x;

void enQ(int u){
    if(x == 110) x = 0;
    Q[x] = u;
    x++;
}

int deQ(void){
    if(h == 110) h = 0;
    return Q[h++];
}

void bfs(int s){
    
    int i, u, e = 0;
    
    for(u = 1; u <= n; u++){
        c[u] = 0;
        d[u] = 1000;
    }
    
    c[s] = -1;
    d[s] = 0;
   
    enQ(s);
    e++;
    
    while(e != 0){
        u = deQ();
        e--;
        for(i = 1; i <= n; i++){
            if(c[i] == 0 && G[u][i] == 1){
                c[i] = -1;
                d[i] = d[u] + 1;
                enQ(i);
                e++;
            }
        }
        c[u] = 1;
    }
}

int main(){
    
    int i, j, k, u, v;
    
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            G[i][j] = 0;
        }
    }
    
    t = 0;
    
    for(i = 1; i <= n; i++){
        scanf("%d%d", &u, &k);
        for(j = 1; j <= k; j++){
            scanf("%d", &v);
            G[u][v] = 1;
        }
    }
    
    bfs(1);
    
    for(i = 1; i <= n; i++){
        if(d[i] == 1000) d[i] = -1;
        printf("%d %d\n", i, d[i]);
    }
    
    return 0;
    
}
