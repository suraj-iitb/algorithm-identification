#include<stdio.h>

int main(){

  int A[100],i,j,minj,N,x,count=0;

  scanf("%d",&N);
  if(N>=1 && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    for(i=0;i<=N-1;i++){
      minj=i;
      for(j=i;j<=N-1;j++){
	if(A[j]<A[minj])
	  minj=j;
	
      }
      x=A[minj];
      A[minj]=A[i];
      A[i]=x;
      if(minj!=i)count++; 
    }
  }
    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
  return 0;
}
