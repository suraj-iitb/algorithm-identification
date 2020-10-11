#include <stdio.h>
int main() {

  int j,tmp,flag,N,count=0;

  //entering the number
  scanf("%d",&N);
  int A[N];

  for(j=0;j<N;j++) scanf("%d",&A[j]);
  //Here is end of entering


  //judgement
  flag=1;
  while (flag) {
    flag = 0;
    for (j = N-1; j>0; j--) {
      if (A[j] < A[j-1]) {
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	flag = 1;
	count++;
      }
    }
  }

  for(j=0;j<N-1;j++)
    printf("%d ",A[j]);
  
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}

