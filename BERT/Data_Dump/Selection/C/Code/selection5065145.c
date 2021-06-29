#include <stdio.h>
#include <stdlib.h>

#define N 100
int main(){
  int A[N], a, b, i, j, n, minj, key;
  int  count=0;

  scanf("%d", &n);
  if(n<1 || n>100)exit(1);

  for(a=0; a<n; a++){
    scanf("%d", &A[a]);
    if(A[a]<0 || A[a]>100)exit(2);
  }

  for(i=0; i<n; i++){
    minj=i;

    for(j=i; j<n; j++){
      if(A[j]<A[minj]) minj=j;
    }

    if(i != minj) count++;

    key=A[i];
    A[i]=A[minj];
    A[minj]=key;
  }

  for(b=0; b<n; b++){
    if(b<n-1) printf("%d ", A[b]);
    else printf("%d\n", A[b]);
  }
  printf("%d\n", count);
  return 0;

}
