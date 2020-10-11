#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001
#define true 1
#define false 0
typedef struct{
  char kind;
  int num;
} card;
int isStable(card *, card *); /*出力が安定であるか判定する関数*/
void merge(card *, int, int, int);
void mergeSort(card *, int, int);
int partition(card *, int, int);
void quicksort(card *, int, int);
int n;

int main()
{
  int i;
  card A[100000], in_copy[100000];
  
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) scanf(" %c %d",&A[i].kind,&A[i].num);

  for(i = 0 ; i < n ; i++) in_copy[i] = A[i];
  
  quicksort(A, 0, n-1);
  /*安定なソートであるバブルソートより高速なマージソートを判定用の比較
  に使用する。*/
  mergeSort(in_copy, 0, n);

  if(isStable(A, in_copy) == true) printf("Stable\n");
  else if(isStable(A, in_copy) == false) printf("Not stable\n");

  for(i = 0 ; i < n ; i++) printf("%c %d\n",A[i].kind,A[i].num);

  return 0;
}

int partition(card *A, int p, int r)
{
  int x, i, j;
  card for_change;
  
  x = A[r].num;
  i = p - 1;

  for(j = p ; j < r ; j++){
    if(A[j].num <= x){
      i++;
      for_change = A[i];
      A[i] = A[j];
      A[j] = for_change; }
  }

  for_change = A[i+1];
  A[i+1] = A[r];
  A[r] = for_change;

  return ++i;
}

void quicksort(card *A, int p, int r)
{
  int q;
  
  if( p < r){
    q = partition(A, p , r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r); }

}

int isStable(card *in, card *out)
{
  int i;

  for(i = 0 ; i < n ; i++){
    if(in[i].kind != out[i].kind) return false; }

    return true;  
} 

void merge(card *A, int left , int mid, int right)
{
  int n1, n2, i, j, k;
  card *L, *R;
  n1 = mid - left;
  n2 = right - mid;

  L = (card *)malloc((n1 + 1) * sizeof(card));
  R = (card *)malloc((n2 + 1) * sizeof(card));

  for(i = 0 ; i < n1 ; i++) L[i] = A[left+i];
  for(i = 0 ; i < n2 ; i++) R[i] = A[mid+i];

  L[n1].num = INFTY;
  R[n2].num = INFTY;

  i = 0;
  j = 0;

  for(k = left ; k < right ; k++){
    if(L[i].num <= R[j].num){
      A[k] = L[i];
      i++; }
    else{
      A[k] = R[j];
      j++; }
  }

  free(L);
  free(R);
  
}

void mergeSort(card *A, int left, int right)
{
  int mid;

  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right); }

}
