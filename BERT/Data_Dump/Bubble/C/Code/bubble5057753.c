#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[100],B[100],N,i,j,flag=1,sum=0;
  scanf("%d",&N);
  if(N<1 || N>100) exit(1);

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  while(flag == 1){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
        B[j] = A[j];
        A[j] = A[j-1];
        A[j-1] = B[j];
        flag = 1;
        sum++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",sum);
  return 0;
}
