#include<stdio.h>
int main()
{
  int N,A[1000],i,j,v,k;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);

  for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while(j >=0 && A[j]>v)
	{
	  A[j+1]=A[j];
	  j=j-1;
	  A[j+1]=v;
	}
      for(k=0;k<N-1;k++){
	printf("%d ",A[k]);
      }
      printf("%d\n",A[k]); 
    }
  return 0;
}