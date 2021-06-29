#include <stdio.h>

static const int N = 100;

void trace(int A[], int n, int count){
  int i;
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

int main(){
  int i, j, n, mini, a;
  int count=0;
  int A[N];
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  
  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++)
      if(A[j] < A[mini]) mini = j;
    if(A[i] == A[mini])continue;
    a = A[i];
    A[i] = A[mini];
    A[mini] = a;
    count++;
  } 
  trace(A, n, count);
  return 0;
}
