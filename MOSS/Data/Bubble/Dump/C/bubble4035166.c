#include <stdio.h>
#define N 100

int main()
{
  int a=0;
  int n,k,i,j,A[N];
  int flag;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	a++;
	flag=1;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)  printf(" ");
  }

  printf("\n%d\n",a);

  return 0;
}

