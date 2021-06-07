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
  d[1]=0;
  for(i=1;i<=n;i++){
    printf("%d %d",i,d[i]);
    printf("\n");
  }
  return 0;
}

void sosa(int a){
  static int b=0;
  int i=1;
  d[a]=b;
  b++;
  while(A[a][i]!=NULL){
    if(d[A[a][i]]==NULL || d[A[a][i]]>b){
      sosa(A[a][i]);
      b--;
     }
    i++;
  }
  if(a==1){
    for(i=1;i<=n;i++){
      if(d[i]==NULL){
		d[i]=-1;
      }
    }
  }
}



