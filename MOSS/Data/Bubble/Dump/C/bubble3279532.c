#include<stdio.h>
int bubbleSort(int [],int);
void shutsu(int [],int);

int main(){
  int N,i;
  int A[100];
  int x;

  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  x = bubbleSort(A,N);
  shutsu(A,N);
  printf("%d\n",x);
  return 0;
}
  
int bubbleSort(int A[],int N){
  int temp;
  int flag = 1;
  int i = 0,j; 
  while(flag){
    flag = 0;
    for(j = N-1;j >= 1;j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	i++;
      }
    }
  }
  return i;
}

void shutsu(int A[],int N){
  int i;
  for(i = 0;i < N;i++){
    if(i > 0)
      printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

	

