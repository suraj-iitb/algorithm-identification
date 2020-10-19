/*マージソートは安定だから、それと比べる。*/
#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000
#define INFINITY 1000000001

struct Card{
  char suit;
  int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1].value = INFINITY;
  R[n2].value = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}
void mergeSort(struct Card A[], int left, int right){
  int mid;
  if(left + 1 != right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int partition(struct Card A[], int p, int r){
  int i, j;
  struct Card x, temp;
  x = A[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].value <= x.value){
      i = i + 1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i + 1];
  A[i + 1] = A[j];
  A[j] = temp;
  
  return i + 1;
}
void quickSort(struct Card A[], int n, int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}

int main(){
  int n, i, v;
  struct Card A[MAX], B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %d" , &S[0], &v);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
}

  mergeSort(A, 0, n);
  quickSort(B, n, 0, n - 1);

  for(i = 0; i < n; i++){
    if(A[i].suit != B[i].suit) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n", B[i].suit, B[i].value);
  }
  
  return 0;
}
