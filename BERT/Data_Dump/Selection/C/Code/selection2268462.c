#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,*A,i,j,minj,c=0,a=0;

  scanf("%d",&N);

  A=(int*)malloc(N*sizeof(int));

 
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  
  for(i=0;i<N;i++){

    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
        }


    a=A[i];
  
    A[i]=A[minj];
    A[minj]=a;
    if(i!=minj) c++;
  }
  printf("%d",A[0]);
  for(i=1;i<N;i++)printf(" %d",A[i]);
  printf("\n%d\n",c);
  free(A);
  return 0;
  
}
