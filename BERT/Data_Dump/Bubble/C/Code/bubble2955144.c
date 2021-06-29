#include <stdio.h>
#define N 100
int main(){
  int flag=1,n,num=0;
  int i,k,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag=0;
    for(i=n-1;i>=1;i--){
      if(A[i]<A[i-1]){
	k=A[i];
	A[i]=A[i-1];
	A[i-1]=k;
	flag=1;
	num++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1){
printf("%d",A[i]);
 continue;
    }
    printf("%d ",A[i]);
  }
  printf("\n%d\n",num);
  return 0;
}

