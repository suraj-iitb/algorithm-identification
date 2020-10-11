#include <stdio.h>

#define N 100

int main()
{
  int i,j,n,k,d,A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      d = A[j];
      if(A[j]<A[j-1]){
	A[j] = A[j-1];
      A[j-1] = d;
      k++;
      }
    }
  }
    for(i=0;i<n-1;i++) printf("%d ",A[i]);
    printf("%d\n",A[n-1]);
    printf("%d\n",k);

    return 0;
}
  
    
      
      

