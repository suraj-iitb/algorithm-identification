#include<stdio.h>
#define L 100
#define WT 0
#define GR 1
#define BK 2

int n,M[L][L];
int cr[L],d[L],f[L],tl;


void DFSv(int);
void DFS(void);


int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i = 0;i<n;i++){
    for(j = 0;j<n;j++)M[i][j] = 0;
  }

  for(i = 0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j =0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }

  }

  DFS();

  return 0;
}

void DFS(){
  int a;

  for(a =0;a<n;a++) cr[a] = WT;
  tl = 0;
  for(a= 0;a<n;a++){
    if(cr[a]==WT)DFSv(a);
  }
  for(a =0;a<n;a++){
    printf("%d %d %d\n",a+1,d[a],f[a]);
  }
}


void DFSv(int b){
  int a;
  cr[b] = GR;
  d[b] = ++tl;
  for(a = 0;a<n;a++){
    if(M[b][a]==0) continue;
    if(cr[a]== WT){
      DFSv(a);
    }


  }
  cr[b] = BK;
  f[b] = ++tl;
}


