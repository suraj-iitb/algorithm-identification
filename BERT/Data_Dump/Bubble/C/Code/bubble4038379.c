#include<stdio.h>
int main(){
  int N,i,j,A[100],count = 0,temp,flag=1; 
   scanf("%d",&N);

   for(i = 0;i < N;i++){
     scanf("%d",&A[i]);
     
   }
 
  i=0;
  while(flag){
    flag = 0;
    for(j = N-1;j > i;j--){
      if(A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;

        flag = 1;
        count++;
      }
     
    }i++;
  }

  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
    
  }
  printf("\n%d\n",count);
  /*for(i = 0;i < N-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);
 printf("%d\n",count);
  */
  return 0;
}

