#include <stdio.h>
int main() {

  int N,i,j,c=0,b,minj;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++) {
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++) {
    minj = i;
    for(j=i;j<N;j++){	
      if(A[j] < A[minj]) minj = j;
    }
    if(minj != i) {
      b = A[i];
      A[i] = A[minj];
      A[minj] = b;
      c++;
    }
  }
  
  for(i=0;i<N;i++) {
    if(i>0) printf(" "); 
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}
