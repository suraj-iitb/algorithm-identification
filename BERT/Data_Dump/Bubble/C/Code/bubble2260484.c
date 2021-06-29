#include <stdio.h>
#define N 100

int main()
{
  int A[N], n, i, j, k, count=0;
  
  scanf("%d",&n);
  
  for (i=0;i<n;i++){
    scanf("%d", &A[i]);
  }

  for (i=0;i<=n-1;i++){
    for (j=n-1;j>=i+1;j--){
      if (A[j]<A[j-1]){
	k=A[j]; 
	A[j]=A[j-1]; 
	A[j-1]=k;
	count++;
      }
    }
  }
  
  for (i=0;i<n;i++){
    if(i>=1) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n", count);
  
  return 0;
}
