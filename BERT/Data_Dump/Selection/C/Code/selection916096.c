#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,A[100],j,N,mini,temp,count=0,flag=0;
  scanf("%d",&N);
  if (N<1 || N>100){
    printf("N 1-100 ni shiro.\n");
    exit(1);
  }

  for (i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for (i=0;i<=N-1;i++){
    mini = i;
    flag=0;
    for (j=i;j<=N-1;j++){
      if (A[j]<A[mini]){
        mini = j;
        flag=1;
      }
    }
    if(flag==1){
      temp=A[i];
      A[i]=A[mini];
      A[mini]=temp;
      count++;
    }
  }

  for (i=0;i<N;i++){
    printf("%d",A[i]);
    if (i<N-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}
