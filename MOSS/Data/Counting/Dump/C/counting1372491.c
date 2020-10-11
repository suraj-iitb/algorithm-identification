#include <stdio.h>
#include <stdlib.h>

int n;
int A[2000001];
int B[2000001];
int C[10001];
int main(){
  int i,j;
  int k=10000;

  scanf("%d",&n);

  i=1;
  while(i<n+1){ 
    scanf("%d",&A[i]);
    i++;
  }



  for(i=0;i<k+1;i++) C[i]=0;

  for(j=1;j<n+1;j++) C[A[j]]++;

  for(i=1;i<k+1;i++) C[i]=C[i]+C[i-1];
 
  for(j=1;j<n+1;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<n+1;i++){
    printf("%d",B[i]);
    if(i<n)printf(" ");
    else printf("\n");

  }

  return 0;
}
