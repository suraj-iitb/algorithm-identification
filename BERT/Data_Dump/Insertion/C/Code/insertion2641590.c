#include <stdio.h>
 
#define N 100
 
main(){
  int i,j,v,n,A[N];
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
 
  }
  printf("%d",A[n-1]);
  printf("\n");
   
  for(i=1;i<n;i++){
    v = A[i];
    j = i-1;
     
    while(j >= 0 && A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(j=0;j<n-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d", A[n-1]);
    printf("\n");
  }
  return 0;
}
