#include<stdio.h>

int main(){

  int num,A[100],i,j,k=0,tmp,flag;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }

  
  for(i=0;i<num;i++){
  flag=1;
  
  while(flag){
    flag=0;
    for(j=num-1;j>=i+1;j--){

      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
        k++; 

      }

    }	
  }
  }
  
  for(i=0;i<num-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",k);

return 0;
}
