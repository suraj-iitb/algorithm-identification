#include <stdio.h>
int main ()
{
  int N1,N2,i,j,a,A[10000],A1[100000],k=0,key;
	scanf("%d",&N1);
	for(i = 0;i<N1;i++)scanf("%d",&A[i]);
	
	scanf("%d",&N2);
	for(i=0;i<N2;i++)
	{
		scanf("%d",&A1[i]);
		for(j=0;j<N1;j++)
		{
			if(A[j]==A1[i])
			 {
			 k++;
			 break;
			 }
		}
	}
	printf("%d\n",k);
	return 0;
}
