#include <stdio.h>
#include <stdlib.h>
typedef struct card{
  char m[3];
  int n, num;
}T_card;
void swap(T_card *, T_card *);
void quick(T_card *, int, int);

int main(){
  int n;
  scanf("%d", &n);
  T_card *A;
  A = (T_card *)malloc(sizeof(T_card) * n);
  int i;
  for(i = 0; i < n; i++){
    scanf("%s %d", A[i].m, &A[i].n);
    A[i].num = i;
  }
  quick(A, 0, n);
  int P = 0, j;
  for(i = 1; i < n; i++)
    for(j = i; j < n & A[i].n == A[j].n; j++)
      if(A[i].num > A[j].num)
	P = 1;
  if(P)
    printf("Not stable\n");
  else
    printf("Stable\n");
  for(i = 0; i < n; i++)
    printf("%s %d\n", A[i].m, A[i].n);
  free(A);
  return 0;
}

void quick(T_card *A, int l, int r){
  int i, j;
  if(l != r){
    //    printf("\n l:%d r:%d\n", l, r);
    for(i = l, j = l; i < r - 1; i++)
      if(A[i].n <= A[r - 1].n){
	swap(&A[i], &A[j]);
	j++;
      }
    swap(&A[r - 1], &A[j]);
    //    for(i = l; i < r; i++)
    //      printf("%s %d\n", A[i].m, A[i].n);
    quick(A, l, j);
    quick(A, j + 1, r);
  }
}

void swap(T_card *a, T_card *b){
  T_card tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
