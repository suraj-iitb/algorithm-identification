#include <stdio.h>
#include <stdlib.h>
int main()
{
  int N,x,i,j,minj,count=0;

  scanf("%d\n",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=N-1;i++){
   minj=i;
   for(j=i;j<=N-1;j++){
      if( A[j]<A[minj]){ 
          minj=j;
}
}
          x=A[minj];
          A[minj]=A[i];
          A[i]=x;
if(A[minj]!=A[i])  count++;
     
}

    for(x=0;x<N;x++){
      if(x)printf(" ");
      printf("%d",A[x]);
    }
    printf("\n%d\n",count);

return 0;
}

