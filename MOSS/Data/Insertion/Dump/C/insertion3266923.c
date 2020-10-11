#include<stdio.h>
#define N 100

int main(){
  int i,j,n,key,d;
  int A[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);
  for(d = 0;d < n - 1; d++)  printf("%d ",A[d]);
  printf("%d",A[n - 1]);
  printf("\n"); 

  for(i = 1; i <= n - 1;i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
   for(d = 0;d < n-1; d++) printf("%d ",A[d]);
   printf("%d",A[n - 1]);
    printf("\n"); 
  }
  return 0;
}

