#include <stdio.h>
int main(){
  int N,A[100],i=0,j,tmp,flag=1,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(flag==1){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
   
  return 0;
}
