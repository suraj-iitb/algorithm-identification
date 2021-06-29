#include <stdio.h>

#define MAX (int)1e5+1
#define SENTINEL (int)1e9+1

typedef struct{
    char mark;
    int value;
}Card;

Card L[MAX/2+2], R[MAX/2+2];

void swap(Card *x, Card *y){//値を入れ替える関数
  Card sw;
  sw = *x;
  *x = *y;
  *y = sw;
}

void merge(Card A[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i=0; i<n1; i++) L[i] = A[left + i];
  for(i=0; i<n2; i++) R[i] = A[mid+i];
  L[n1].value = R[n2].value = SENTINEL;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    if(L[i].value<=R[j].value) A[k]=L[i++];
    else A[k]=R[j++];
  }
}

void merge_sort(Card A[], int left, int right){
  if(left+1<right){
    int mid = (left+right) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r){
  int i, j;
  i = p - 1;
  for(j=p; j<=r; j++){
    if(A[j].value<=A[r].value){
      i++;
      swap(&A[i], &A[j]);
    }
  }
  return i;
}

void quick_sort(Card A[], int p, int r){
  int q;
  if(p<r){
    q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
  }
}

int main(){
  Card A[MAX], B[MAX];
  int i, n, v, stable=1;
  char s[10];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s %d", s, &v);
    A[i].mark = B[i].mark = s[0];
    A[i].value = B[i].value = v;
  }

  quick_sort(A, 0, n - 1);
  merge_sort(B, 0, n);

  for(i=0; i<n; i++){
    if(A[i].mark!=B[i].mark){
      stable = 0;
      break;
    }
  }

  printf((stable)?"Stable\n":"Not stable\n");

  for(i=0; i<n; i++) printf("%c %d\n", A[i].mark, A[i].value);

  return 0;
}
