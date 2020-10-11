#include <stdio.h>

int  main () {
  int N,i,flag,tmp,count=0;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++) {
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag) {
    flag=0;
  for(i=N-1;i>=1;i--) {
    if(A[i] < A[i-1]) {
      tmp = A[i];
      A[i] = A[i-1];
      A[i-1]=tmp;
      flag=1;
      count++;
    }
  }
  }
  
 
  for(i=0;i<N;i++) {
    if(i==0) printf("%d",A[i]);

    else printf(" %d",A[i]);
    if(i==N-1) printf("\n");
  }
  printf("%d\n",count);

  return 0;
  }
      
  
      

