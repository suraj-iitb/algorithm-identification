#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100
int n,M[N][N];
int color[N],d[N],f[N],tt;
void dfs_b(int u){
        int i,j,v;
        color[u]=GRAY;
        d[u]= ++tt;
        for(v=0; v<n; v++) {
                if(M[u][v]==0) {
                        continue;
                }
                if(color[v]==WHITE) {
                        dfs_b(v);
                }
        }
        color[u]=BLACK;
        f[u]=++tt;
}
void dfs_a(){
        int u;
        for(u=0; u<n; u++) {
                color[u]=WHITE;
        }
        tt=0;
        for(u=0; u<n; u++) {
                if(color[u]==WHITE) {
                        dfs_b(u);
                }
        }
        for(u=0;u<n;u++){
          printf("%d %d %d\n",u+1,d[u],f[u]);
        }

}
int main(){
        int u,k,v;
        int i,j;


        scanf("%d",&n);
        for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                        M[i][j]=0;
                }
        }
        for(i=0; i<n; i++) {
                scanf("%d%d",&u,&k);
                u--;
                for(j=0; j<k; j++) {
                        scanf("%d",&v);
                        v--;
                        M[u][v]=1;
                }
        }
        dfs_a();
        // for(i=0; i<n; i++) {
        //         for( j=0; j<n; j++) {
        //                 printf("%d",M[i][j]);
        //                 if(j==n-1)
        //                         printf("\n");
        //                 else
        //                         printf(" ");
        //         }
        //
        // }
        return 0;
}

