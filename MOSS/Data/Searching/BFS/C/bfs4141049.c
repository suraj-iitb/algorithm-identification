#include<stdio.h>

int main(){
  int n,m,i,j,k,l,num,renew = 0;

  scanf("%d",&n);

  int A[n+1],M[n+1][n+1];
  for(i = 0;i <= n;i++){
    A[i] = 0;
    for(j = 0;j <= n;j++){
      M[i][j] = 0;
    }
  }

  for(i = 1;i <= n;i++){
    scanf("%d",&num);
    scanf("%d",&m);
    for(j = 1;j <= m;j++){
      scanf("%d",&k);

      M[num][k] = 1;

      if(k == 1) continue;

      if(num != 1 && A[num] == 0) A[num] = -1;
      else if(A[k] == 0) A[k] = A[num] + 1;
      else if(A[k] > A[i] + 1){
        A[k] = A[num] + 1;
        renew = 1;
      }

      if(renew == 1){
        for(l = 1;l <= n;l++){
          if(M[k][l] == 1){
            if(A[l] > A[k] + 1) A[l] = A[k] + 1;
          }
        }
      }
      renew = 0;
    }
  }

  printf("1 %d\n",A[1]);

  for(i = 2;i <= n;i++){
    if(A[i] == 0) A[i] = -1;
    printf("%d %d\n",i,A[i]);
  }
  return 0;
}

