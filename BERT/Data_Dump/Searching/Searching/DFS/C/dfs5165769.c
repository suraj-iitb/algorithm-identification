#include <stdio.h>

int n,M[100][100];
int u,A[100],B[100],C[100];

void fukasa(int);

int main(){
  int a,b,i,j,k,m,l;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&m);
      m--;
      M[a][m]=1;
    }
  }

  for(i=0;i<n;i++){
    A[i]=0;
  }
  u=0;

  for(i=0;i<n;i++){
    if(A[i]==0) fukasa(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,B[i],C[i]);
  }

  return 0;
}
void fukasa(int i){
  int x;

  A[i]=1;
  B[i]=++u;
  for(x=0;x<n;x++){
    if(M[i][x]==0)continue;
    if(A[x]==0)fukasa(x);
  }
  A[i]=2;
  C[i]=++u;
}

