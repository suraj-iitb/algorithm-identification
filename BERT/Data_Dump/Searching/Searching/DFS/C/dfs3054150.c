#include <stdio.h>

int G[100][100], d[100], f[100], C[100];
int t = 1;

void Depth(int);

int main(){
  
  int i, j, n, u;

    scanf("%d", &n);

   
    for (i = 1; i <= n; i++){
        d[i] = f[i] = 0;
        for (j = 1; j <= n; j++){
            G[i][j] = 0;
        }
    }

   
    for (i = 1; i <= n; i++){
        scanf("%d", &u);
        scanf("%d", &C[u]);
	
        for (j = 1; j <= C[u]; j++){
            scanf("%d", &G[u][j]);
        }
    }

    for (i = 1; i <= n; i++){
      
        if (d[i] == 0) Depth(i);
        
    }

    for (i = 1; i <= n; i++){
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    return 0;
}


void Depth(int u){
    int i;

    d[u] = t++;
    
    for (i = 1; i <= C[u]; i++){
      
        if (d[G[u][i]] == 0) Depth(G[u][i]);
    }
    
    f[u] = t++;
}

