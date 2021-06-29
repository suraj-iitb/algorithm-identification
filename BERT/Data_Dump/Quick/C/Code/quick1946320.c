#include <stdio.h>

typedef struct{
  int num;
  char c;
  int key;
}Quick;

Quick A[100001];

int Partition(int, int);
void Quicksort(int, int);

int main(){
  char c1, c2, c3;
  int n, i, x = 0;

  scanf("%d%c", &n, &c1);

  for(i = 0; i < n; i++){
    scanf("%c%c%d%c",&A[i].c, &c2, &A[i].num, &c3);
    A[i].key = i;
  }

  Quicksort(0, n-1);
  for(i =0 ; i < n; i++){
    if(A[i].key > A[i+1].key && A[i].num == A[i+1].num){
      x = 1;
      break;
    }
  }
  if(x == 0) printf("Stable\n");
  if(x == 1) printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c %d\n", A[i].c, A[i].num);
  }
  return 0;
}

int Partition(int p, int r){
  int i, j;
  Quick x, tmp;
  x.num = A[r].num;
  i = p-1;
  for(j = p;j < r;j++){
    if(A[j].num <= x.num){
      i = i + 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i + 1] = A[r];
  A[r] = tmp;
  return i + 1;
}

void Quicksort(int p, int r){
  int q;
  if(p < r){
    q = Partition(p, r);
    Quicksort(p, q-1);
    Quicksort(q + 1, r);
  }
}
