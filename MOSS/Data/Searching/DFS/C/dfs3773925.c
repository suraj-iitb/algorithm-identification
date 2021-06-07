#include <stdio.h>
#define MAX 105

int G[MAX][MAX], f[MAX], d[MAX], dis=0, n;

void visit(int a){
    int i;
    d[a]=dis;
    
    for (i=0; i<n; i++){
        if(G[a][i] == 1 && d[i]==0){
            dis++;
            visit(i);
        }    
    }
    dis++;
    f[a] = dis;
}

int main(void) {
  int u,k,v,i,j;
 
  scanf("%d",&n);
  for(i=0; i<n; i++){
      d[i]=0;
    for(j=0; j<1 ;j++)
      G[i][j] = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    for(j=0; j<k; j++){
          scanf("%d",&v);
          G[u-1][v-1] = 1;
    }
  }
    
  for(i=0;i<n;i++){
    if(d[i]==0){
        dis++;
        visit(i);
    }
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
  return 0;
}



