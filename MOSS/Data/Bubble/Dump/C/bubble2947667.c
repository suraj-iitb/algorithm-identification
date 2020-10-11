#include<stdio.h>
int main(){
  int flag=1,A[100],i,n,count=0,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag=0;
    for(i=n-1;i>=1;i--){
      if(A[i]<A[i-1]){
	tmp=A[i];
	A[i]=A[i-1];
	A[i-1]=tmp;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  
    
		 
  return 0;
}

