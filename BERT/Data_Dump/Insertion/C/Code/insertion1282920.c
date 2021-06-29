#include<stdio.h>
#define N 100
main(){
  int n,A[N],i,j,l,key;
  scanf("%d",&n);
  for(i = 1; i <= n; i++)scanf("%d",&A[i-1]);
  for(i = 1; i <= n; i++){
    for(l = 1; l < n; l++)printf("%d ",A[l-1]);
    printf("%d\n",A[n-1]);
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
  return 0;
}
