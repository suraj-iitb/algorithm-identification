#include<stdio.h>

int main(){

  int N,i,j,k,v,minj,count=0;

  scanf("%d", &N);
  int A[N];

  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  for(i = 0 ; i <= N-1 ; i++){
    minj = i;
    for( j = i ; j <= N-1 ; j++){
      if(A[j] < A[minj])minj = j;
    }
    if(i != minj){
      v = A[i];
      A[i] = A[minj];
      A[minj] = v;
      count++;
    }
  }

  printf("%d",A[0]);
  for(k = 1 ; k < N ; k++)printf(" %d",A[k]);
  printf("\n%d\n",count);
   
 return 0;
}

