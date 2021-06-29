#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int A[N], n, a, i, j, key;
  int count=0, flag=1;

  scanf("%d", &n);
  if(n<1 || n>100) exit(1);

  for(a = 0; a < n; a++){
    scanf("%d", &A[a]);
    if(A[a]<0 || A[a]>100) exit(2);
  }

  while(flag == 1){
    flag=0;

      for(j=n-1; j>0; j--){
        if(A[j]<A[j-1]){
          key = A[j];
          A[j] = A[j-1];
          A[j-1] = key;
          flag = 1;
          count++;
        }
      }
  }

  for(i=0; i<n; i++){
    if(i<n-1) printf("%d ", A[i]);
    else printf("%d\n", A[i]);
  }

  printf("%d\n", count);

  return 0;
}

