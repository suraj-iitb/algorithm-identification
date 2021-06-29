#include<stdio.h>

int main(void){
  int i,j,t,N,A[100],flag=1,count=0;

    scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);


  while(flag){
    flag=0;

    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
        t=A[j];A[j]=A[j-1];A[j-1]=t;
        count++;
        flag=1;
      }
    }
  }
    for(j=0;j<N;j++){
      if(j == N-1)
        printf("%d\n",A[j]);
      else printf("%d ",A[j]);
    }
    printf("%d\n",count);

    return 0;
}


