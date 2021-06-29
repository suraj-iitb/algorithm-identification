#include<stdio.h>

void trace(int A[],int N){
  int i;
 
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
main(){
  int n,i,j,k;
  int A[100];
 
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
 
  trace(A,n);
 for(i=1;i<n;i++){
    k=A[i];
    j=i-1;
    while(j>=0&&A[j]>k){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=k;
    trace(A,n);
  }
 
  return 0;
 
}
