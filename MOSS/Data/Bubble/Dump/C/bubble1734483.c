#include<stdio.h>
#define N 100
  

int main()
{
  int i,j,key,n,flag=1,count=0;
  int A[N];
  scanf("%d",&n);
  if(n>=1&&n<=100){
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  }
 
  while(flag){
    flag=0;
  for(j=n-1;j>=1;j--){
    key=A[j];
    if(A[j]<A[j-1]){
     
    A[j]=A[j-1];
    A[j-1]=key;
    flag=1;
    count++;
    }
  }
  }
  for ( i = 0; i < n-1; i++ ){
  
  printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);
  
  printf("%d\n",count);
  return 0;
}
