#include<stdio.h>
int main(void)
{
  int N,i,j,v,A[1000];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    { scanf("%d",&A[i]); }

  	for(j=0;j<N;j++)
	  {
	    printf("%d",A[j]);
	    if(j != N-1){printf(" ");}
	    else {printf("\n");}
	  }
  for(i=1;i<N;i++)
      { v=A[i];
      for(j=i-1;j>=0 && A[j]>v;j--)
	  {
	    A[j+1]=A[j];
	    A[j]=v;
	  }
	for(j=0;j<N;j++)
	  {
	    printf("%d",A[j]);
	    if(j != N-1){printf(" ");}
	    else {printf("\n");}
	  }
      }
    return 0;
}
