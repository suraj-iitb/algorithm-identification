#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int n, i, j;

  scanf("%d", &n);

  int A[VMAX],B[n],C[n];

  for(i=0;i<n;i++){
        scanf("%d", &C[i]);
 }

for(i=0;i<VMAX;i++){
       A[i]=0;
}

for(j=0;j<n;j++){
    A[C[j]]++;
}

for(i=1;i<VMAX;i++){
    A[i] = A[i] + A[i-1];
}

for(i=n-1;i>=0;i--){
      B[A[C[i]]-1] = C[i];
      A[C[i]]--;
      }

for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1)printf(" ");
}

printf("\n");


  return 0;
}

