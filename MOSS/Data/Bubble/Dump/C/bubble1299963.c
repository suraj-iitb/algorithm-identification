#include<stdio.h>

#define N 100

void bubbleSort(int A[], int n);

int main()
{
  int i, n, A[N];
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  
  bubbleSort(A, n);
  
  return 0;
}

void bubbleSort(int A[], int n)
{
  int i, j, temp, a = 0;

  if(n != 1){
    for(i = 0; i < n; i++){
      for(j = (n - 1); j > 0; j--){
	if(A[j] < A[j-1]){
	  temp = A[j-1];
	  A[j-1] = A[j];
	  A[j] = temp;
	  a++;
	}
      }
    }
  }
  for(i = 0; i < n; i++){
if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", a);

  return 0;
}
