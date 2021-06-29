#include<stdio.h>
     
int main()
{
  int i,j,v,A[100],N,s;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
        for(s=0;s<N;s++)
	{
	  if(s>0) printf(" ");
	  printf("%d",A[s]);
	}
      printf("\n");

  
  for(i=1;i<=N-1;i++)
    {
      v=A[i];//ittan
      j=i-1;
      while(j>=0 && A[j]>v)
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1]=v;
      for(s=0;s<N;s++)
	{
	  if(s>0) printf(" ");
	  printf("%d",A[s]);
	}
      printf("\n");
    }


  return 0;
}
  


