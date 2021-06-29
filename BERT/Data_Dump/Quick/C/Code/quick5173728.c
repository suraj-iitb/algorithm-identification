#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card{
  char suit;
  int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card Z[], int n, int left, int mid, int right){
  int i, j, k, n1 = mid - left, n2 = right - mid;

  for(i = 0; i < n1; i++) L[i] = Z[left+i];
  for(i = 0; i < n2; i++) R[i] = Z[mid+i];

  L[n1].value = R[n2].value = SENTINEL;

  i = j = 0;

  for(k = left; k < right; k++){
    if(L[i].value <= R[j].value){
      Z[k] = L[i++];
    }
    else Z[k] = R[j++];
  }
}

void mergeSort(struct Card Z[], int n, int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    
    mergeSort(Z, n, left, mid);
    mergeSort(Z, n, mid, right);
    merge(Z, n, left, mid, right);
  }
}

int partition(struct Card Z[], int n, int p, int r){
  int i, j;
  struct Card a, b;
  
  b = Z[r];
  i = p-1;

  for(j = p; j < r; j++){
    if(Z[j].value <= b.value){
      i++;
      a= Z[i];
      Z[i] = Z[j];
      Z[j] = a;
    }
  }
  a = Z[i+1];
  Z[i+1] = Z[r];
  Z[r] = a;

  return i+1;
}

void quickSort(struct Card Z[], int n, int p, int r){
  int q;

  if(p < r){
    q = partition(Z, n, p, r);
    quickSort(Z, n, p, q-1);
    quickSort(Z, n, q+1, r);
  }
}

int main(){
  int n, i, j, stable = 1;
  struct Card X[MAX], Y[MAX];
  char N[10];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %d", N, &j);
    X[i].suit = Y[i].suit = N[0];
    X[i].value = Y[i].value = j;
  }
  mergeSort(X, n, 0, n);
  quickSort(Y, n, 0, n-1);

  for(i = 0; i < n; i++){
    if(X[i].suit != Y[i].suit) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++) printf("%c %d\n", Y[i].suit, Y[i].value);

  return 0;
}

