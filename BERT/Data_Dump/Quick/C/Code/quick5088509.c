#include <stdio.h>
#include <stdlib.h>
#define VMAX 100000
#define MAX 1000000000

typedef struct{
  char mark;
  int num;
}card;

card L[VMAX/2+2], R[VMAX/2+2];

int partition(card *A, int p, int r){
  card x, v;
  x.num = A[r].num;
  int i = p-1;
  for(int j=p;j<=r-1;j++){
    if(A[j].num <= x.num){
      i = i+1;
      v = A[i];
      A[i] = A[j];
      A[j] = v;
    }
  }
  v = A[i+1];
  A[i+1] = A[r];
  A[r] = v;
  return i+1;
}

void quicksort(card *A, int p, int r){
  int q;
  if (p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void merge(card *A, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1].num = R[n2].num = MAX;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(L[i].num <= R[j].num){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(card *A, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i, j, n, flag=0;
  card A[VMAX], in[VMAX];

  scanf("%d", &n);
  if(n > VMAX) exit(1);

  for(i=0;i<n;i++){
    scanf("%s %d", &A[i].mark, &A[i].num);
    if(A[i].num > MAX) exit(2);
    in[i] = A[i];
  }

  quicksort(A, 0, n-1);
    mergeSort(in, 0, n);

  for(i=0;i<n;i++){
    if(A[i].mark != in[i].mark) flag=1;
  }

  if(flag==1) printf("Not stable\n");
  else if(flag==0) printf("Stable\n");

  for(i=0;i<n;i++) printf("%c %d\n", A[i].mark, A[i].num);

  return 0;
}
