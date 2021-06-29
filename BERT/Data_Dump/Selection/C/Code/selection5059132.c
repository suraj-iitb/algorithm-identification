#include <stdio.h>

int main(void)
{
	int N,*A,i,j,minj,count=0,change,comp,cnt;
	scanf("%d",&N);
	A=(int *)malloc(N * sizeof(int));
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	for(i=0;i<N-1;i++)
	{	minj=0;
		comp=A[i];
		cnt=0;
		for(j=i+1;j<=N-1;j++)
		{
			if(comp > A[j])
			{
				comp=A[j];
				minj=j;
				cnt++;
				continue;
			}
		}
		if(cnt>0)
		{
		change=A[i];
		A[i]=A[minj];
		A[minj]=change;
		count++;
		}
	}
	for(i=0;i<N-1;i++)
	printf("%d ",A[i]);
	printf("%d\n",A[i]);
	printf("%d\n",count);
	
	return 0;
}
