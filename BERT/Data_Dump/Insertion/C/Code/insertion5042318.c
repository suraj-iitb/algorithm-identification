#include<stdio.h>
#include<stdlib.h>

void print_array(int *, int);

int main()
{
  int N;
  
  scanf("%d",&N);
  if(N < 1 || N > 100) {
    exit(1);
  }
  
  int i, j, v;
  int A[N];

  for(i = 0 ; i < N ; i++){
    scanf("%d", &A[i]);
    if(A[i] < 0 || A[i] > 1000) {
      exit(2);
    }
  }

  print_array(A,N);

  for(i = 1 ; i < N ; i++) {
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;
    print_array(A, N);
  }

  return 0;
}

void print_array(int *a, int n)
{
  int i;
  for(i = 0 ; i < n ; i++) {
    printf("%d",a[i]);
    if(i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
