#include<stdio.h>
int bubbleSort(int A[],int N){
  int i,j,temp,count=0;
  for(i=0;i<N;i++){
    //  printf("a\n");
  for(j = N-1;j>i;j--){
    // printf("a\n");
    if(A[j] < A[j-1]){
      temp=A[j];
      A[j]=A[j-1];
      A[j-1]=temp;
      // A[j] ??¨ A[j-1] ?????????
      count++;
    }
  }
}
    return count;
    }
int main(){
  int N,i,flag;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 flag=bubbleSort(A,N);
 for(i=0;i<N;i++){
   if(i>0) printf(" ");
   printf("%d",A[i]);
 }
   printf("\n");
   // printf(" ");
 printf("%d\n",flag);
 return 0;
}
