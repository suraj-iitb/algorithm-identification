#include <stdio.h>
#include <math.h>

int main(){
  int v,n,i,j,k,l,flag,tmp,count = 0;
  scanf("%d", &n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
  }

  flag = 1;
  while(flag == 1){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
        flag = 1;
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        count++;
      }
    }

  }

  for(l=0;l<n;l++){
    printf("%d", A[l]);
    if(l != n-1){
      printf(" ");
    }
  }
    printf("\n");
    printf("%d\n", count);

  return 0;
}
