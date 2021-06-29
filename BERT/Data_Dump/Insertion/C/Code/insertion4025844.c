#include<stdio.h>

int main(){

  int N,i,j,k,v;

  scanf("%d", &N);
  int A[N];

  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  for( i=1 ; i <= N-1 ; i++){
    printf("%d",A[0]);
    for(k=1;k<N;k++)printf(" %d",A[k]);
    printf("\n");
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]= v;    
   }
  
  printf("%d",A[0]);
  for(k=1;k<N;k++)printf(" %d",A[k]);

  printf("\n");
  
 return 0;

}

