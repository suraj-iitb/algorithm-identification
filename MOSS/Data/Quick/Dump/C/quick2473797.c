#include <stdio.h>
#define MAX 100000
struct Card{
  char a;
  int b;
};
struct Card L[MAX/2+2], R[MAX/2+2];
int n;
 
void merge(struct Card A[], int left, int mid, int right){
  int n1, n2, i, j, k;
 
  n1 = mid - left;
  n2 = right - mid;
 
  for(i = 0; i <= n1-1; i++) L[i] = A[left + i];
  for(i = 0; i <= n2-1; i++) R[i] = A[mid + i];
  L[n1].b = 1000000001;
  R[n2].b = 1000000001;
  i = j = 0;
  for(k = left; k <= right-1; k++){
    if(L[i].b <= R[j].b){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}
 
void mergeSort(struct Card A[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left, mid);
    mergeSort(A,mid, right);
    merge(A,left, mid, right);
  }
}
int partition(struct Card A[], int p, int r){
  int i, j;
  struct Card x, t;
  x = A[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].b <= x.b){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;
  return i+1;
}
 
void Quicksort(struct Card A[], int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}
int main()
{
  int i, v, f = 0;
  struct Card x[MAX], y[MAX];
  char s[10];
 
  scanf("%d", &n);
 
  for(i = 0; i < n; i++){
    scanf("%s %d", s, &v);
    x[i].a = y[i].a = s[0];
    x[i].b = y[i].b = v;
  }
  Quicksort(x, 0, n-1);
  mergeSort(y, 0, n);
 
  for(i = 0; i < n; i++){
    if(x[i].a != y[i].a) f = 1;
  }
  if(f == 0) printf("Stable\n");
  else printf("Not stable\n");
 
  for(i = 0; i < n; i++) printf("%c %d\n", x[i].a, x[i].b);
  return 0;
}
