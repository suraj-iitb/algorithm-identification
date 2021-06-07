#include <stdio.h>
#define MAX 101
int M[MAX][MAX];
int ID[MAX];
int F[MAX];
int D[MAX];
int flag[MAX];
int n;
int d=0;
void discover(int);
int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n+1;i++){
    flag[i]=0;
    for(j=0;j<n+1;j++){
      M[i][j] = 0;
    }
  }
   for(i=1;i<n+1;i++){
    scanf("%d",&u);
    ID[i] = u;
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      M[i][v] = 1;
    }
  }
   for(i=1;i<n+1;i++){
     if(flag[i] == 0) discover(i);
   }
   for(i=1;i<n+1;i++){
      printf("%d %d %d\n",ID[i],D[i],F[i]);
    }

}

void discover(int v){
 
  int i,j;
  D[v] = ++d;
  flag[v] = 1;
    for(i=1;i<n+1;i++){
      if(M[v][i]==0) continue;
      if(flag[i] == 0) {
	discover(i);
      }   
    }
    flag[v] = 2;
  F[v] = ++d;
}

