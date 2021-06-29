#include<stdio.h>
int main(){
  int A[100],N,flag=1,i,j,k,key,cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  k=0;
  while(flag){
    flag=0;
    for(j=N-1;j>k;j--){
      if(A[j]<A[j-1]){
        key=A[j];
        A[j]=A[j-1];
        A[j-1]=key;
        flag=1;
        cnt++;
      }
    }
    k++;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",cnt);
  return 0;
}
