#include<stdio.h>
int main()
{
  int i,j,flag,tmp,count=0,N,A[100];
  scanf("%d",&N);
  for(i=0;i<N && N<=100 && N>=1;i++)
    {
      scanf("%d",&A[i]);
    }
  flag=1;
    while(flag!=0)
      {
	flag=0;
	for(j=N-1;j>=1;j--)
	  {
	    if(A[j]<A[j-1])
	      {
		tmp=A[j];
		A[j]=A[j-1];
		A[j-1]=tmp;
		flag=1;
		count++;
	      }
	  }
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
  
  

