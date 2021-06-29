#include<stdio.h>
int main(){
  int A[100],N;
  int i,j,k,flag=1,temp,num=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
      }


  while(flag){
    flag=0;
    for(j=N-1;j>0;--j){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	num++;
      }
    }
  }

  printf("%d",A[0]);
    for(j=1;j<N;j++){
      printf(" %d",A[j]);
    }
    printf("\n");
    printf("%d\n",num);

    return 0;
    
}
