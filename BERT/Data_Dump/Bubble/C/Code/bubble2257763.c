#include<stdio.h>
#define N 100
int main (){
  int flag,i,j,A[N],count=0,n,x;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
    
  
  flag = 1;
  i = 0;
  
  while(flag!=0){
    flag=0;

  
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	x=A[j];
	A[j]=A[j-1];
	A[j-1]=x;
	flag=1;
	count++;
      }
    }
    i++;
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);
  
  return 0;
}
