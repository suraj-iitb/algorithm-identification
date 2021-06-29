#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000
#define INF 1000000000

typedef struct{
  int value;
  char suit;
}Card;

Card L[MAX], R[MAX];

void merge(Card A[], int left, int mid, int right)
{
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1].value = INF;
  R[n2].value = INF;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right)
{
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r)
{
  int n, i, j;
  Card x, tmp;

  x = A[r];
  i = p - 1;

  for(j = p; j < r; j++){
    if(A[j].value <= x.value){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp;

  return i + 1;
}

void quickSort(Card A[], int p, int r){
  int q;

  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main(void){
  int i, n, v, stable = 1;
  char S[10];
  Card X[MAX], Y[MAX];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %d", S, &v);
    X[i].value = v;
    Y[i].value = v;
    X[i].suit = Y[i].suit = S[0];
  }

  mergeSort(X, 0, n);
  quickSort(Y, 0, n - 1);

  for(i = 0; i < n; i++){
    if(X[i].suit != Y[i].suit){
      stable = 0;
    }
  }

  if(stable == 1) printf("Stable\n");
  else  printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c %d\n", Y[i].suit, Y[i].value);
  }

  return 0;
}

