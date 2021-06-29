#include<stdio.h>

int main(){
  int i,flag=1,t,cnt=0,n,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(A[i]<A[i-1]){
	cnt++;
	t=A[i];
	A[i]=A[i-1];
	A[i-1]=t;
	flag=1;
      }
    }
  }
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],cnt);
  return 0;
}

