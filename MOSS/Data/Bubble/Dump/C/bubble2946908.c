#include<stdio.h>
#define N 100

int main()
{
  int i,flag=1,A[N],n,ch,count=0;
  
  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag=0;
    for(i=n-1; i>0; i--){
      if(A[i] < A[i-1]){
	ch=A[i];
	A[i]=A[i-1];
	A[i-1]=ch;
	count++;
	flag=1;
      }
    }
  }
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

