#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N,x,i,j,flag=1,count=0;

  scanf("%d\n",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if (A[j]< A[j-1]) {
        i = A[j-1];
        A[j-1] = A[j];
        A[j] = i;
	count++;
	flag=1;
      }
    }
  }


    for(x=0;x<N;x++){
      if(x)printf(" ");
      printf("%d",A[x]);
    }
    printf("\n%d\n",count);

    return 0;
}
