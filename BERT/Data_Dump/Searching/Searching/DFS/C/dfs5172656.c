#include <stdio.h>
#include <math.h>
 
#define N_LIMIT 110
#define WHITE 0
#define BLACK 1
#define GRAY 2
 
int n,darr[N_LIMIT],farr[N_LIMIT],garr[N_LIMIT][N_LIMIT],couleur[N_LIMIT],t=0;
 
void dfssearch(int);
void print(int x);
 
int main(){
  int i,j,u,v,k;
   
  scanf("%d",&n);

  for(i=1;i<= n; i++){
    for(j=1; j<= n; j++){
      garr[i][j] = 0;
    }
  }
 
  for(i=1; i<= n; i++){
    scanf("%d%d",&u,&k);

    for(j=0; j<k; j++){
      scanf("%d",&v);

      garr[u][v] = 1;
    }
  }
 
   for(i=1; i<=n; i++){
     couleur[i] = WHITE;
    }
 
   for(i=1; i<=n; i++){
     if(couleur[i] == WHITE) dfssearch(i);
   }
 
  for(i=1; i<=n; i++){
    printf("%d ",i);
    printf("%d ",darr[i]);
    printf("%d\n",farr[i]);
  }
   
  return 0;
}

void dfssearch(int u){
  int v;
   
  couleur[u] = GRAY;
  t++;
  darr[u] = t;
   
  for(v=1; v<=n; v++){
    if((garr[u][v] == 1)&& (couleur[v] == WHITE)){
      dfssearch(v);
 
    }
  }
 
  couleur[u] = BLACK;
  farr[u]= ++t;
}

void print(int x){
    printf(" ");
}
