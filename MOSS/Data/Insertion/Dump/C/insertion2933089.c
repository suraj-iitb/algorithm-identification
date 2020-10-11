#include <stdio.h>

int main()
{
  int i,j,k,n,tmp;
  int A[500];

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  
  for(i=1;i<=n;i++){
    tmp = A[i];
    j = i-1;
    for(k=0;k<n;k++){
      if(k < n-1){
	printf("%d ",A[k]);
      }
      else  printf("%d\n",A[k]);
    }
    while(j >= 0 && A[j] > tmp){
      A[j+1] = A[j];
      j--;
      A[j+1] = tmp;
    }
  }
      
  return 0;
}

