#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define a 10001
void CountingSort(int);
int C[a],A[N],B[N],n;
main(){
  int i,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i]) k=A[i];
  }
  CountingSort(k);
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i==n) printf("\n");
    else printf(" ");
  }
  
  return 0;
  
}

void CountingSort(int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j]]=C[A[j]]+1;
  }
  for(i=0;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
 

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
}
