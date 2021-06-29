#include<stdio.h>

int sentaku(int*,int);

int main()
{
  int A[100],N,a,sum;

  scanf("%d",&N);
  for(a=0;a<N;a++)
    {
      scanf("%d",&A[a]);
    }
  sum=sentaku(A,N);

  for(a=0;a<N;a++)
    {
      if(a>0)
	{
	  printf(" ");
	}
      printf("%d",A[a]);
    }
  printf("\n");
  printf("%d\n",sum);

  return 0;
}

int sentaku(int A[],int N)
{
  int a,b,c,sum=0,num;

  for(a=0;a<N-1;a++)
    {
      num=a;
      for(b=a;b<N;b++)
	{
	  if(A[b]<A[num])
	    {
	      num=b;
	    }
	}
      c=A[a];
      A[a]=A[num];
      A[num]=c;
      if(a!=num)
	{
	  sum++;
	  }
    }
  return sum;
}

