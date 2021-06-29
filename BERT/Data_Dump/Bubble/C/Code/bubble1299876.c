#include<stdio.h>
int main(){
  int i,j,n,flag,temp,count=0,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  }
  
  flag=1;
  i=0;
  while(flag){
   
    flag = 0;
    for(j=n-1;j>=i+1;j--){

      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
	flag =1;
      }
     
    }
    
    i++;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);
  return 0;
}
