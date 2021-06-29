#include <stdio.h>

#define MAX 100

int BubbleSort(int [],int);
void swap(int [],int,int);

int main(){
  int A[MAX],N;
  int i;
  int answer;

  scanf("%d",&N);

  for (i = 0;i < N;i++)
    scanf("%d",&A[i]);

  answer = BubbleSort(A,N);

  for (i = 0;i < N;i++){
    if (i)
      printf(" ");

    printf("%d",A[i]);
  }

  printf("\n%d\n",answer);
  return 0;
}

int BubbleSort(int A[],int N){
  int cnt = 0;
  int flag = 1;
  int i,j;

  i = 0;
  
  while (flag){
    flag = 0;

    for (j = N - 1;j != i;j--)
      if (A[j - 1] > A[j]){
	swap(A,j - 1,j);
	cnt++;
	flag = 1;
      }
    
    i++;
    
  }

  return cnt;
}

void swap(int A[],int a,int b){
  int temp;

  temp = A[a];
  A[a] = A[b];
  A[b] = temp;
}

