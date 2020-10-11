#include <stdio.h>

int main() {
  int i, j, n, minj, tmp;
  scanf("%d",&n);
  int A[n];
  for(i=0; i<n; i++)
    scanf("%d", &A[i]);
  int cnt=0;
  for(i=0; i<n; i++) {
    minj=i;
    for(j=i+1; j<n; j++) {
      if(A[j]<A[minj]) minj=j;
    }
    if(A[i]>A[minj]) {
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      cnt++;
    }
  }
  for(i=0; i<n; i++) {
    if(i) printf(" ");

    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

