#include<stdio.h>
int main(){
  int N,i,j,A[100],flag=1,B,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j] < A[j-1]){
	B=A[j];
	A[j]=A[j-1];
	A[j-1]=B;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1)
      printf(" ");
    else printf("\n");
  }
  printf("%d\n",count);
  return 0;
}
