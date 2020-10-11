#include <stdio.h>
int main(void) {
  int N;
  scanf("%d",&N);
  int A[N];
  int i,j,k;
  
  for(i=0;i<N;i++) {
    scanf("%d",&A[i]);
  }
  
  int tmp;
  
  for(i=0;i<N;i++) {
    printf("%d",A[i]);
    if(i!=N-1)
      putchar(' ');
  }
  putchar('\n');
  
  for(i=1;i<N;i++) {
    j=i;
    while(j>0 && A[j]<A[j-1]) {
      tmp=A[j];
      A[j]=A[j-1];
      A[j-1]=tmp;
      j--;
    }
    for(k=0;k<N;k++) {
      printf("%d",A[k]);
      if(k!=N-1)
	putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}

