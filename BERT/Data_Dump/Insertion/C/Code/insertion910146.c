#include <stdio.h>

int main()
{
  int key,i,j,n,k;
  int A[100];

 scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  
  for(i=0;i<n;i++){
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key)
      {
	A[j+1]=A[j];
	j--;
      }
    A[j+1]=key;
    
    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k<n-1){
	printf(" ");
      }
	else if(k=n-1) break;
    }
    printf("\n");
  }
  return 0;
}
