/*
�N�C�b�N�\�[�g
�p�[�e�B�V�����Ɠ���

���͗�
6
D 3
H 2
D 1
S 3
D 2
C 1

���͗�
Not stable
D 1
C 1
D 2
H 2
D 3
S 3

*/

#include <stdio.h>
#include <stdlib.h>
#define NMAX 100000
#define AMAX 1000000000 //10^9

typedef struct{
  char mark;
  int num;
}Card;

int n;
Card L[NMAX/2+2], R[NMAX/2+2];

int partition(Card *A, int p, int r){
  Card x, v;
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

void quicksort(Card *A, int p, int r){
  int q;
  if (p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void merge(Card *A, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1].num = R[n2].num = AMAX;
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

void mergeSort(Card *A, int left, int right){
  if(left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i, j, k=0, f=0;
  Card A[NMAX], B[NMAX];

  scanf("%d", &n);
  if(n > NMAX) exit(1);

  for(i=0;i<n;i++){
    scanf("%s %d", &A[i].mark, &A[i].num);
    if(A[i].num > AMAX) exit(2);
    B[i] = A[i];
  }

  quicksort(A, 0, n-1);
  mergeSort(B, 0, n);

  for(i=0;i<n;i++){
    if(A[i].mark != B[i].mark) f=1;
  }

  if(f==1)      printf("Not stable\n");
  else if(f==0) printf("Stable\n");

  for(i=0;i<n;i++) printf("%c %d\n", A[i].mark, A[i].num);

  return 0;
}
