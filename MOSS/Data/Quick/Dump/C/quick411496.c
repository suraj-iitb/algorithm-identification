#include <stdio.h>
#define exchange(a,b) {typeof(a) __tmp=a;a=b;b=__tmp;}


char A[100001];
int B[100001];


int Partition(int A[], int p, int r) {
  int i,j;
  int x;
  x = A[r];
  i = p-1;
  for(j = p; j < r; ++j) {
    if(B[A[j]] <= B[x]) { // if(A[j] <= x) {
      i = i+1;
      exchange(A[i], A[j]);
    }
  }
  exchange(A[i+1], A[r]);
  return i+1;
}

void Quicksort(int A[], int p, int r) {
  int q;
  if(p < r) {
    q = Partition(A,p,r);
    Quicksort(A,p,q-1);
    Quicksort(A,q+1,r);
  }
}

int isStable(int A[], int n) {
  int i;
  for(i = 2; i <= n; ++i) {
    if(B[A[i-1]] == B[A[i]] && A[i-1] > A[i]) return 0;
  }
  return 1;
}

int main() {
  int i;
  int n;
  int C[100001];
  scanf("%d", &n);
  for(i = 1; i <= n; ++i) {
    scanf(" %c %d", A+i,B+i);
    C[i] = i;
  }
  Quicksort(C,1,n);
  if(isStable(C,n)) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 1; i <= n; ++i) {
    printf("%c %d\n", A[C[i]], B[C[i]]);
  }
  return 0;
}
