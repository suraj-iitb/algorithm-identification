#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

typedef struct{
  char suit;
  int val;
}Card;

Card L[MAX/2 + 2], R[MAX/2 + 2];

void merge(Card *, int, int, int, int);
void mergeSort(Card *, int, int, int);
int partition(Card *, int, int, int);
void quickSort(Card *, int, int, int);

int main(){
  int n = 0, v = 0;
  int i = 0;
  Card A[MAX], B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%s %d",S,&v);
    A[i].suit = B[i].suit = S[0];
    A[i].val = B[i].val = v;
  }

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  for(i = 0; i < n; i++){
    /*compare with merge and quick*/
    if(A[i].suit != B[i].suit)stable = 0;
  }

  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i = 0; i < n; i++){
    printf("%c %d\n",B[i].suit,B[i].val);
  }
  
  return 0;
}

void merge(Card *A, int n, int left, int mid, int right){
  int i = 0, j = 0, k = 0;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0; i < n1; i++){
    
    L[i] = A[left + i];
    
  }
  for(i = 0; i < n2; i++){
    
    R[i] = A[mid + i];
    
  }

  L[n1].val = R[n2].val = SENTINEL;

  i = 0;

  for(k = left; k < right; k++){
    
    if(L[i].val <= R[j].val)A[k] = L[i++];
    else A[k] = R[j++];
    
  }
}

void mergeSort(Card *A, int n, int left, int right){
  int mid = 0;

  if(left+1 < right){
    
    mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
    
  }
}

int partition(Card *A, int n, int p, int r){
  int i = 0, j = 0;
  Card t, x;

  x = A[r];
  i = p-1;
  for(j = p; j < r; j++){
    if(A[j].val <= x.val){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;

  return i + 1;
}

void quickSort(Card *A, int n, int p, int r){
  int q = 0;

  if(p < r){
    q = partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}

