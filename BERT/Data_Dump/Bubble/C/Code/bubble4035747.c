#include<stdio.h>

int main(){
  int A[100],N,temp,j,i,flag;
  int count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
    flag = 1; // 逆の隣接要素が存在する
    while(flag){
           flag = 0;
       for(j=N-1;j>=1;j--){
	 if(A[j] < A[j-1]){
	   temp=A[j-1];
	   A[j-1]=A[j];
	   A[j]=temp;
	   count++;
	   
	   flag=1;
	 }
	 }
    }
  for(i=0;i<N-1;i++){
  printf("%d ",A[i]);
  }
  for(i=N-1;i<N;i++){
     printf("%d\n",A[i]);
  }
  printf("%d\n",count);
       
  return 0;
}

