#include<stdio.h>

void bubbleSort(int A[] , int n){
  int i,j,temp,num=0;
  for(i = 0;i < n; i++){
    for(j = n - 1; j >= 1; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	num++;
      }
    }
  }
   for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i== n-1)  break;
      printf(" ");
   }
   printf("\n%d\n", num);
}
int main(){
  int i,j,N,temp,num=0;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  bubbleSort(A,N);
  return 0;
}
