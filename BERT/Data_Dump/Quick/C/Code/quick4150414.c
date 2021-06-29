#include <stdio.h>
#define N 100000
#define INF 2147483647

struct Pair{
  char c;
  int num;
};

struct Pair X[N / 2 + 2], Y[N / 2 + 2];

void merge(struct Pair A[], int n, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i = 0; i < n1; i++){
    X[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    Y[i] = A[mid + i];
  }
  X[n1].num = INF;
  Y[n2].num = INF;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(X[i].num <= Y[j].num){
      A[k] = X[i++];
    }else {
      A[k] = Y[j++];
    }
  }
}

void mergeSort(struct Pair A[], int n, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int partition(struct Pair A[], int n, int p, int r){
  int i, j;
  struct Pair t, g;
  g = A[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].num <= g.num){
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

void quickSort(struct Pair A[], int n, int p, int r){
  int q;
  if(p < r){
    q = partition(A, n, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}

int main(){
  int i, n, v;
  struct Pair A[N], B[N];
  char cc[10];
  int stable = 1;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %d", cc, &v);
    A[i].c = cc[0];
    B[i].c = A[i].c;
    A[i].num = v;
    B[i].num = A[i].num;
  }

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n - 1);

  for(i = 0; i < n; i++){
    if(A[i].c != B[i].c){
      stable = 0;
    }
  }

  if(stable == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  for(i = 0; i < n; i++){
    printf("%c %d\n", B[i].c, B[i].num);
  }

  return 0;
}

