#include<stdio.h>
#include<stdlib.h>
#define N 2000001

int main()
{
  int n,i,j,k=0;
  scanf("%d",&n);
  int A[n+1],B[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    if(k<A[i+1])k=A[i+1];
                  }
  int C[k+1];
  for(i=0;i<=k;i++)/*countingsort*/
    C[i]=0;

  for(i=0;i<n;i++)
    C[A[i+1]]++;

  for(i=1;i<=k;i++)
    C[i]=C[i]+C[i-1];

  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;    } 
                  
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
     printf("%d",B[i]);
    }
  printf("\n");
  return 0;
}
