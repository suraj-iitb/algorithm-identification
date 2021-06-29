#include <stdio.h>

#define INF 2000000000

int L[250002],R[250002];
int cnt=0;

void merge(int A[],int n,int l, int m, int r){
  int i,j,k,n1,n2;
  n1 = m - l;
  n2 = r - m;
  for (i = 0; i < n1; i++) {
    L[i] = A[l + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[m + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  i = 0, j = 0;
  for (k = l; k < r; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergesort(int A[],int n,int l,int r){
  int m;
  if (l+1 < r) {
    m = (l + r)/2;
    mergesort(A,n,l,m);
    mergesort(A,n,m,r);
    merge(A,n,l,m,r);
  }
}

int main() {
  int i,n,A[500000];

  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d",&A[i]);
  }

  mergesort(A,n,0,n);

  for (i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

