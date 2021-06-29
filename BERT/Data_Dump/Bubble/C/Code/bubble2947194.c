#include <stdio.h>

int main(){
  int N,i,j,cnt=0,tmp=0,flag=1,A[100];
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag==1){
    flag=0;
    
    for(j=N-1;j>0;j--){      
      if (A[j] < A[j-1]){
	tmp=A[j];   //A[j] と A[j-1] を交換
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
  } 
  
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;
}

