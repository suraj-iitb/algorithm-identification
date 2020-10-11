#include<stdio.h>

int main( ){

  int A[100],i,minj,N,a,count=0,j;


  scanf("%d",&N);

  for(i=0;i<N;i++){

    scanf("%d",&A[i]);

  }


  for(i=0;i<N;i++){

    minj=i;

    for(j=i;j<N;j++){

      if(A[j]<A[minj]) minj=j;
    }

      a=A[i];
      A[i]=A[minj];
      A[minj]=a;

      if(minj != i) count++;   
    
  }

  for(i=0;i<N;i++){
  
    if(i==N-1) printf("%d\n%d\n",A[i],count);
    else printf("%d ",A[i]);
  }

  return 0;
}
