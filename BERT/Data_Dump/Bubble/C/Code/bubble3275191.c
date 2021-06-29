#include<stdio.h>
#define NMAX 100

int count = 0;

void bubbleSort(int[], int);
void output(int[], int);

int main(){

  int N, i, j;
  int A[NMAX];

  scanf("%d", &N);
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);

  bubbleSort(A, N);
  output(A, N);
  
  return 0;
}

void bubbleSort(int A[], int N){

  int j, tmp, flag = 1;

  while(flag){

    flag = 0;
    
    for(j = N - 1; j >= 1; j--){
      if(A[j] < A[j - 1]){

	tmp = A[j];
	A[j] = A[j - 1];
	A[j - 1] = tmp;

	flag = 1;
	count++;
      }
     
    }
  }

}

void output(int A[], int N){

  int i;

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);
}
  

