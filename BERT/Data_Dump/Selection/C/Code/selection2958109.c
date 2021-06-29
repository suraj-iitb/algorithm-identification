#include <stdio.h>
#include <stdlib.h>
int main(){
  int flag,i,j,size,n,tmp,c=0,k;
  int minj;
  int *A;
  scanf("%d",&size);
  A = (int *)malloc(size * sizeof(int));

  for(i=0;i<=size-1;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<=size-1;i++){
   flag = 0;
    minj = i;
    for(j=i; j<=size-1; j++){
       
      if(A[j] < A[minj]){
	minj = j;
	if(flag == 0){
	  c++;
	  flag = 1;
	}
      }
    }
    if(flag = 1){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
    }
      /*  
    for(k=0;k<size-1;k++){
    printf("%d ",A[k]);
    }
    printf("%d\n",A[k]);
      */
  }

  for(i=0;i<size-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",c);
  return 0;
}

