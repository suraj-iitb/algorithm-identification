#include <stdio.h>
#include <stdbool.h>
#define N 100000
#define SENTINEL 200000000

typedef struct{
  char suit;
  int value;
}card;

card L[N/2+2], R[N/2+2];

void merge(card A[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;
  n1=mid-left;
  n2=right-mid;
  for(i=0; i<n1; i++){
    L[i]=A[left+i];
  }
  for(i=0; i<n2; i++){
    R[i]=A[mid+i];
  }
  L[n1].value=SENTINEL;
  R[n2].value=SENTINEL;
  i=0;
  j=0;
  for(k=left; k<right; k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergesort(card A[], int n, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A, n, left, mid);
    mergesort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

void swap(card *a, card *b){
  card temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int partition(card A[], int n, int p, int r){
  card x, t;
  int i, j;
  x=A[r];
  i=p-1;
  for(j=p; j<r; j++){
    if (A[j].value<=x.value){
      i=i+1;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i+1], &A[r]);
  return i+1;
}

void quickSort(card A[], int n, int p, int r){
  int q;
  if(p<r){
    q=partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}

bool isStable(card in[], card out[], int n){
  int i;
  for(i=0; i<n; i++){
    if(in[i].suit!=out[i].suit) return false;
  }
  return true;
}

int main()
{
  int n, i, v, stable=1;
  card A[N], B[N];
  char s[10];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s%d", s, &v);
    A[i].suit=B[i].suit=s[0];
    A[i].value=B[i].value=v;
  }

  mergesort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  if(isStable(A, B, n)==true) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++){
    printf("%c %d\n", B[i].suit, B[i].value);
  }
  return 0;
}
