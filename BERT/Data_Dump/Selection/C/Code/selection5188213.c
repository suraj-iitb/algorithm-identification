#include <stdio.h>

int main(void) {
  int i, j, n, minimum,t, counter;
  counter =0;
  scanf("%d",&n);
  int A[n];
  for (i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for (i =0; i<n-1;i++){
    minimum = i;
    for (j=i;j<n;j++){
      if (A[j]<A[minimum]){
        minimum =j;
      }
    }
    if (i!= minimum){
      counter = counter +1;
    }
    t = A[minimum];
    A[minimum] = A[i];
    A[i] = t;
    

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
