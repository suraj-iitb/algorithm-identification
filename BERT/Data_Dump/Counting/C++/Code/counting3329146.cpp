#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

#define SIZE 2000001
#define COUNT_SIZE 10001

int main(void)
{
  int *A, *B;
  int i, j, n, C[COUNT_SIZE];

  scanf("%d", &n);
  
  A = (int *)malloc(sizeof(int) * (n + 1));
  B = (int *)malloc(sizeof(int) * (n + 1));
 
  for(i = 0;i <= COUNT_SIZE;i++){
    C[i] = 0;
  }

  for(j = 1;j <= n;j++){
    scanf("%d",&A[j]);
    C[A[j]]++;
  } 

  for(i = 1;i <= COUNT_SIZE;i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j = n;j >= 1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
    }

  for(i = 1;i < n;i++){
    printf("%d ", B[i]);
  }

  printf("%d\n", B[i]);
  
  return 0;
}

