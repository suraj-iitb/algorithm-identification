#include<stdio.h>
int main()
{
  int A[100];
  int N,i,j,minj,count=0,tmp;
  scanf("%d",&N);
  for(i=0;i<N && 1<=N && N<=100;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
        {
          if(A[j]<A[minj])
            {
              minj=j;
            }
	}
      if(minj!=i) count++;
	  tmp=A[i];
	  A[i]=A[minj];
	  A[minj]=tmp;
    }
   for(i=0;i<N;i++)
    {
  printf("%d",A[i]);
  if(i!=N-1)printf(" ");
    }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

