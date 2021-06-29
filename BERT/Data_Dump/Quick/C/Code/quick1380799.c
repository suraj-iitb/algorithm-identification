#include<stdio.h>

typedef struct{
  char mark[2];
  int number;
  int order;
} Card;

int partition(Card *A, int p, int r){
  int i, j, a;
  Card x;

  a = A[r].number;
  i = p - 1;

  for(j = p; j < r; j++){
    if(A[j].number <= a){
      i++;

      x = A[i];
      A[i] = A[j];
      A[j] = x;
    }
  }

  x = A[i + 1];
  A[i + 1] = A[r];
  A[r] = x;

  return i + 1;
}

void quickSort(Card *A, int p, int r){
  int q;

  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main(){
  Card A[100000];
  int n, i, j, v = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%s %d",A[i].mark, &A[i].number);
    A[i].order = i + 1;
  }

  quickSort(A, 0, n - 1);

  for(i = 0; i < n; i++){
    if(A[i].order > A[i + 1].order && A[i].number == A[i + 1].number){
      v++;
      break;
    }
  }

  if(v == 0) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++) printf("%s %d\n",A[i].mark, A[i].number);

  return 0;
}
