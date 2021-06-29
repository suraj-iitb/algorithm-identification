#include <stdio.h>

typedef struct{
  char moji;
  int num;
  int count;
} Card;

int partition(Card [], int, int);
void quicksort(Card [], int, int);

int main(){
  int n, i, stable = 1;
  Card A[100000];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf(" %c%d", &A[i].moji, &A[i].num);
    A[i].count = i;
  }

  quicksort(A, 0, n-1);

  for(i = 1; i < n; i++){
    if(A[i].num == A[i-1].num && A[i].count < A[i-1].count){
      stable = 0;
      break;
    }
  }

  if(stable) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++) printf("%c %d\n", A[i].moji, A[i].num);
  
  return 0;
}

int partition(Card A[], int p, int r){
  int x, i, j;
  Card temp;
  x = A[r].num;
  i = p-1;
  for(j=p; j<r; j++){
    if(A[j].num <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  
  return i+1;
}

void quicksort(Card A[], int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}
