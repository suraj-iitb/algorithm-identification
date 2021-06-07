#include <stdio.h>

int main(void) {
  int n,m,j,i, counter,b;
  counter = 0;
  scanf("%d",&n);
  int A[n];
  for (i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&m);
  int B[m];
  for (j=0;j<m;j++){
    scanf("%d",&B[j]);
  }
  for(j=0;j<m;j++){
    for(i=0;i<n;i++){
      if (A[i] == B[j]){
        counter = counter +1;
        break;
      }
    }
  }
  printf("%d\n",counter);
}

