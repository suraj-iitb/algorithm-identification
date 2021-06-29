#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card{
  char suit;
  int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], int n, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
  for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  i = j = 0;
  for ( k = left; k < right; k++ ){
    if ( L[i].value <= R[j].value ){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}
 
void mergeSort(struct Card F[], int n, int left, int right ){
  int mid;
  if ( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(F, n, left, mid);
    mergeSort(F, n, mid, right);
    merge(F, n, left, mid, right);
  }
}

int partition(struct Card V[], int n, int p, int r){
  int i, j;
  struct Card t, x;
  x = V[r];
  i = p - 1;
  for ( j = p; j < r; j++ ){
    if ( V[j].value <= x.value ){
      i++;
      t = V[i];
      V[i] = V[j]; 
      V[j] = t;
    }
  }
  t = V[i+1];
  V[i+1] = V[r];
  V[r] = t;
  return i+1;
}

void quickSort(struct Card K[], int n, int p, int r){
  int q;
  if ( p < r ){
    q = partition(K, n, p, r);
    quickSort(K, n, p, q - 1);
    quickSort(K, n, q + 1, r);
  }
}

int main(){
  int n, i, v;
  struct Card U[MAX], T[MAX];
  char S[10];
  int stable = 1;
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    scanf("%s %d", S, &v);
    U[i].suit = T[i].suit = S[0];
    U[i].value = T[i].value = v;
  }

  mergeSort(U, n, 0, n);
  quickSort(T, n, 0, n-1);

  for ( i = 0; i < n; i++ ){
    if ( U[i].suit != T[i].suit ) stable = 0;
  }

  if ( stable == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  for ( i = 0; i < n; i++ ) {
    printf("%c %d\n", T[i].suit, T[i].value);
  }
}
