#include <stdio.h>
#define MAX 1001
#define W 0
#define B 1
#define G 2
void DFS(int);
int n,d[MAX],f[MAX],g[MAX][MAX],cl[MAX],t=0;

int main(){
        int i,j,u,v,k;
        scanf("%d",&n);
        for(i=1; i <= n; i++) {
                for(j=1; j<= n; j++) {
                        g[i][j] = 0;
                }
        }
        for(i=1; i<= n; i++) {
                scanf("%d%d",&u,&k);
                for(j=0; j<k; j++) {
                        scanf("%d",&v);
                        g[u][v] = 1;
                }
        }
        for(i=1; i<=n; i++) {
                cl[i] = W;
        }
        for(i=1; i<=n; i++) {
                if(cl[i] == W) DFS(i);
        }
        for(i=1; i<=n; i++) {
                printf("%d ",i);
                printf("%d ",d[i]);
                printf("%d\n",f[i]);
        }
        return 0;
}

void DFS(int u){
        int v;
        cl[u] = G;
        t++;
        d[u] = t;
        v=0;
        while(v<=n) {
                ++v;

                //  printf("check\n");
                if((g[u][v] == 1)&& (cl[v] == W)) {
                        DFS(v);
                }
        }

        cl[u] = B;
        f[u]= ++t;
}
