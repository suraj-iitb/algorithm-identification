#include<stdio.h>

void sosa(int);
int d[101],f[101],A[101][101],n;

int main(){
  int m,t,l,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&t,&m);
    for(j=1;j<=m;j++){
      scanf("%d",&A[t][j]);
    }
  }
  sosa(1);
  for(i=1;i<=n;i++){
    printf("%d %d %d",i,d[i],f[i]);
    printf("\n");
  }
  return 0;
}

void sosa(int a){
  static int b=1;
  int i=1;
  d[a]=b;
  b++;
  while(A[a][i]!=NULL){
    if(d[A[a][i]]==NULL){
      sosa(A[a][i]);
      b++;
     }
    i++;
  }
  f[a]=b;
  if(a==1 && n*2 !=b){
    b++;
    for(i=1;i<=n;i++){
      if(d[i]==NULL){
	sosa(i);
	b++;
      }
    }
  }
}


