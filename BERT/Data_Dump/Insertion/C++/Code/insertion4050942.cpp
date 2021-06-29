#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,N=0,v,i,j;

  scanf("%d",&N);

  int A[N];

  if(N>100||N<1) exit(1);
  
  for(n=0; n<N; n++){
    scanf("%d",&A[n]);
    if(A[n]<0||A[n]>1000) exit(2);
  }

  for(n=0; n<N; n++){
    if(n!=0) printf(" %d",A[n]);
    else printf("%d",A[n]);
  }

  printf("\n");

  for(i=1; i<N; i++){
    v = A[i];
    j = i - 1;
    
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }

    for(n=0; n<N; n++){
      if(n!=0) printf(" %d",A[n]);
      else printf("%d",A[n]);
    }
    printf("\n");
  }
  
  return 0;
}

