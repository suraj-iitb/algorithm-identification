#include <stdio.h>
int main(){
  int n,j,i,k,v;
  int A[1000];
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }
  for(i=1;i<=n-1;i++){

    for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d",A[n-1]);
    printf("\n");
    //
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      
      A[j+1]=A[j]; 
      j--;
    } 
    A[j+1]=v;
    //

  }
  for(k=0;k<n-1;k++){
    printf("%d ",A[k]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  
  return 0;
}
