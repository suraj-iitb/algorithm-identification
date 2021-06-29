#include <stdio.h>

int main(){
  int flag,i,minj,j,N,A[100],tmp,count=0;
  flag = 1;
  i = 0;
  
  scanf("%d",&N);
  if(N > 100 || N < 0) return 0;
  
  while(i < N){
    scanf("%d",&A[i]);   
   if(A[i] > 100 || A[i] < 0) return 0;
   
   i++;
  }
 
    for(i = 0 ; i <= N - 1;i++){
      minj = i;
      
      for(j = i; j <= N -1;j++){
	if (A[j] < A[minj]){
	  minj = j;
	}
      }
      if(i != minj){
      tmp = A[minj];
      A[minj] = A[i];
      A[i] = tmp;
      count++;
      }
    }
  	
for(j = 0; j <= N-2;j++){
  	printf("%d ",A[j]);
 }
 printf("%d",A[j]);

 printf("\n%d\n",count);

  return 0;
}

