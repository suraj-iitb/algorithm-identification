#include <stdio.h>

int main()
{
  int n,i,j,a,flag,cnt=0;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	a=A[j-1];
	A[j-1]=A[j];
	A[j]=a;
	cnt++;
      }
    }
  }

  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

