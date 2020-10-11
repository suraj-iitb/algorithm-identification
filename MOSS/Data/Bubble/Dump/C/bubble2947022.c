#include <stdio.h>
#define N 100
int main(){

  int n,flag,i,j,temp,A[N],count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(j=1;j<=n-1;j++){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	count++;
      }
    }

  }
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j==n-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
