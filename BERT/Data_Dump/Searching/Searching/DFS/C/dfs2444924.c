
  #include <stdio.h>
#define N 100
#define A 1
#define B 2
#define C 3

int n,d[N],f[N],time,S[N],G[N][N];

void DFS(void);
void DFSiku(int);

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }

  DFS();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DFS(void){
  int i;
  
  for(i=0;i<n;i++){
    S[i]=A;
  }
  time=0;
  for(i=0;i<n;i++){
    if(S[i]==A){
      DFSiku(i);
    }
  }
}

void DFSiku(int u){
  int i;

  S[u]=B;
  d[u]=++time;

  for(i=0;i<n;i++){
    if(G[u][i]==1 && S[i]==A){
      DFSiku(i);
    }
  }

  S[u]=C;
  f[u]=++time;
}
