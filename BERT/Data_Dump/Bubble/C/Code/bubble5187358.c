#include <stdio.h>

int main() {
  int n, i, j,t, counter;
  counter = 0;
  scanf("%d",&n);
  int A[n];
  for (i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for (i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if (A[j]<A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
        counter = counter +1;
      }
    }

  }
  for (i=0;i<n;i++){
    if(i == n - 1){
        printf("%d\n",A[i]);
    }else{
      printf("%d ", A[i]);
    }
  }
  printf("%d\n",counter);
}
