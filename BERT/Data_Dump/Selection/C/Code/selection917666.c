#include<stdio.h>

int main(){

  int A[100];
  int i,j,N,k;
  int change=0;
  int mini;

  scanf("%d",&N);
  for(i=0; i<N; i++)scanf("%d",&A[i]);

  for(i=0; i<N; i++){
      mini=i;
      for(j=i; j<N; j++){
          if(A[j]<A[mini])mini=j;
        }

      if(mini!=i){
          k=A[i];
          A[i]=A[mini];
          A[mini]=k;
          change++;
        }
    }

  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  
  printf("%d\n",A[i]);
  printf("%d\n",change);
  
  return 0;
}
