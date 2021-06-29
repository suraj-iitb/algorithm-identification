#include<stdio.h>
int main(){
  int i,N,A[100],con=0,j,tmp,flag ;
  //入力
  scanf("%d",&N);
  if(N >= 1 && N <= 100){
    for (i = 0; i < N; i++){ //printf("k");
    scanf("%d",&A[i]); 
  }
  }
 flag = 1;
  while(flag ){
    flag = 0;
    for ( j = N-1; j >= 1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
        A[j] = A[j-1];
	A[j-1] = tmp; 
      flag = 1;
	con++;
      }
   
    }
    }
    //出力
   for (i = 0; i < N-1; i++){  
     printf("%d ",A[i]);
  }
   printf("%d\n",A[N-1]);


   printf("%d\n",con);
 
   
  return 0;
}
