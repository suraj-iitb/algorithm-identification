#include <stdio.h>
void bubbleSort(int A[100],int N);
int main(){
  int A[100],N,i;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,N);
  return 0;
}

void bubbleSort(int A[100],int N){
  int flag=1,tmp,count=0,j;
  while(flag==1){
  flag = 0;
   for(j = N-1;j>=1;j--)
     if(A[j] < A[j-1]){
       count++;
       tmp = A[j];
       A[j] = A[j-1];
       A[j-1] = tmp;
       flag = 1;
     }
   }
    for(j=0;j<N;j++){
      if(j<N-1){
     printf("%d ",A[j]);
      }
      if(j==N-1){
       printf("%d",A[j]);
       printf("\n");
      }
    }
      printf("%d",count);
      printf("\n");
}

