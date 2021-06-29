#include <stdio.h>
#define N 100

int main(){
  int flag=1,n,j,tmp,A[N],cnt=0;

  scanf("%d",&n);
  for(j=0;j<n;j++)  
    scanf("%d",&A[j]);

  while(flag){
    flag=0;
    for(j=n-1;j>0;j--)
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cnt++;
      }
  }

  printf("%d",A[0]);
  for(j=1;j<n;j++)  
    printf(" %d",A[j]);
  printf("\n%d\n",cnt);

  return 0;
}
