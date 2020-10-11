#include <stdio.h>

int main(){
  int flag,i,j,N,A[100],tmp,count=-1;
  flag = 1;
  i = 0;
  scanf("%d",&N);
  if(N > 100 || N < 0) return 0;  
  while(i < N){
    scanf("%d",&A[i]);   
   if(A[i] > 100 || A[i] < 0) return 0;   
   i++;
  }
  while(flag){
    flag = 0;

    for(j = N -1 ; j >= 1;j--){
      if(A[j] < A[j-1] ){

	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	flag = 1;
	break;
      }
    }
  	count++;	
  }
for(j = 0; j <= N-2;j++){
  	printf("%d ",A[j]);
 }
 printf("%d",A[j]);

 printf("\n%d\n",count);

  return 0;
}

