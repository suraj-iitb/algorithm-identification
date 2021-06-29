#include<stdio.h>
#include<stdlib.h>

int selection(int *,int);

int main(){
  int N,*A,i,c;
  
  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  c = selection(A,N);
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",c);
  return 0;
}

int selection(int *A,int N){
  int i,mini,j,k,c=0;
  for(i=0;i<N;i++){
    mini = i;
    for(j=i;j<N;j++){
      if(A[j] < A[mini])mini = j;
    }
    if(mini != i){
      k = A[i];
      A[i] = A[mini];
      A[mini] = k;
      c++;
    }
  }
  return c;
}



  

