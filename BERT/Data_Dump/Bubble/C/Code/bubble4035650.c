#include<stdio.h>

int main(){

  int N,i,j,k,v,count=0;

  scanf("%d", &N);
  int A[N];

  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  for( i = 0 ; i < N-1 ; i++){
    for( j = N-1 ; j > i ; j--){      
      if(A[j] < A[j-1]){
	v = A[j];
	A[j] = A[j-1];
	A[j-1] = v;  
	count++;	
      }
    }
  }
  printf("%d",A[0]);
  for(k=1;k<N;k++)printf(" %d",A[k]);
  printf("\n%d\n",count);
  
 return 0;

}

