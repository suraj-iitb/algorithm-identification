#include <stdio.h>
#define N 100

int main()
{
  int A[N],n,i,j,k,count=0,minj;
  
  scanf("%d",&n);
  
  for (i=0;i<n;i++){
    scanf("%d", &A[i]);
  }
  
  for (i=0;i<=n-1;i++){
    minj=i;
    for (j=i;j<=n-1;j++){
      if (A[j]<A[minj]){
	minj=j;
      }
    }
	k=A[i]; 
	A[i]=A[minj]; 
	A[minj]=k;
	if(i!=minj){
	  count++;
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
