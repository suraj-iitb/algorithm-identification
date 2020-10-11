#include <stdio.h>
#define N 100
main(){
  int n,A[N],a,count=0,i,j;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(A[j] < A[j-1]){
        a = A[j];
        A[j] = A[j-1];
        A[j-1] = a;
        count++;
      }
    }
  }
  for(i = 0; i < n; i++){
    if (i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
