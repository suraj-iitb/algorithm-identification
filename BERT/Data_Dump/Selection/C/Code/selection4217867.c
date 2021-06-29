#include <stdio.h>

#define MAX 100

int SelectionSort(int [],int);
void swap(int [],int,int);

int main(){
  int A[MAX],N;
  int answer;
  int i;

  scanf("%d",&N);

  for (i = 0;i < N;i++)
    scanf("%d",&A[i]);

  answer = SelectionSort(A,N);
  
  for (i = 0;i < N;i++){
    if (i)
      printf(" ");

    printf("%d",A[i]);
  }

  printf("\n%d\n",answer);
  
  return 0;
}

int SelectionSort(int A[],int N){
  int minj,cnt = 0;
  int i,j;

  for (i = 0;i < N - 1;i++){
    minj = i;
    
    for (j = i;j < N;j++)
      if (A[j] < A[minj])
	minj = j;

    if (minj != i){
    swap(A,i,minj);
    cnt++;
    }
    
  }

  return cnt;
}

void swap(int A[],int i,int minj){
  int temp;

  temp = A[i];
  A[i] = A[minj];
  A[minj] = temp;
}

