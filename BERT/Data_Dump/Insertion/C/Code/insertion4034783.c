#include<stdio.h>

#define N 100

int main()
{
  int i,j = 0,a,v,n;
  int A[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);
  for(a = 0; a < n - 1 ; a++) printf("%d ",A[a]);
	
  printf("%d",A[n-1]);
	printf("\n");
   for(i = 1; i < n; i++)
    {
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v){
	A[j + 1] = A[j];
	j--;
	A[j + 1] = v;
      }
      for(a = 0; a < n-1; a++){
	  printf("%d ",A[a]);
	}
      printf("%d",A[n-1]);
	printf("\n");	
      }
  return 0;
}

