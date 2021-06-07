#include<stdio.h>

#define M 150
 
int A[M][M],B[M];
int C[M],D[M], s;
 
void X(int );
 
int main(){
  int i,j,a,n;
  scanf("%d", &n);
  s=1;
  for(i=1;i<=n;i++){
    
    C[i]=D[i]=0;
    
    scanf("%d",&a);
    
    scanf("%d",&B[a]);
    
    for(j=1;j<=B[a];j++) scanf("%d",&A[a][j]);
  }
  for(i=1;i<=n;i++)if(!C[i])X(i);
  for(i=1;i<=n;i++)printf("%d %d %d\n",i,C[i],D[i]);
  return 0;
}
void X(int x){
  int k;
  C[x] = s++;
  for(k=1;k<=B[x];k++) if(!C[A[x][k]]) X(A[x][k]);
  D[x] = s++;
}

