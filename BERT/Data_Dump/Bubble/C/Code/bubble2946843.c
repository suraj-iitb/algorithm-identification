#include<stdio.h>
int main(){
  int N,i,flag=1,temp,num=0;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  /*bubble sort*/
  while(flag){
    flag=0;
    for(i=N-1;i>=1;i--){
      if(A[i]<A[i-1]){
	temp=A[i];
	A[i]=A[i-1];
	A[i-1]=temp;
	flag=1;
	num++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",num);
  return 0;
}
