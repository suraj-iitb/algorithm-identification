#include <stdio.h>
#include <stdlib.h>

int main(){

  int i,j,N,tmp,b,flag = 1,cnt=0;

  scanf("%d",&N);

  int A[N];

  if(N<1 && N>100) exit(1);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
    if(A[i]<0||A[i]>100) exit(2);
  }

  while(flag){
    flag = 0;
    for(j=N-1; j>0; j--){
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        cnt++;
      }
    }
  }

  for(i=0; i<N; i++){
    if(i!=0) printf(" %d",A[i]);
    else printf("%d",A[i]);
  }
  
  printf("\n%d\n",cnt);
  
  return 0;
}
