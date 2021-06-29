#include <stdio.h>

int main(){
  int i,N,A[100],con=0,j,tmp,minj ; 
  scanf("%d",&N);
  for (i = 0;i <= N-1; i++){
    scanf("%d",&A[i]); 
  }
  for (i = 0; i <= N-1; i++){
    minj = i;
    for (j = i; j <= N-1; j++){
      if (A[j] < A[minj]){
	minj = j;
      }
    }
    if(minj!=i){
    tmp = A[i];
    A[i] =  A[minj];
    A[minj] = tmp;
    con++;
    }
  }

for (i = 0; i < N-1; i++){  
  printf("%d ",A[i]);
 }
printf("%d\n",A[N-1]);


   printf("%d\n",con);
 
   



  return 0;
}
