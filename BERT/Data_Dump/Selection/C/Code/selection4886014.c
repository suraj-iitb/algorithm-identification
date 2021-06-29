#include <stdio.h>

int main()
{
	int Seq[100],i,min,SwapCount=0,N;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&Seq[i]);
	for(i=0;i<N;i++)
	{
		int temp,j;
		min=i;
		for(j=i;j<N;j++)
			if(Seq[j]<Seq[min])
				min=j;
		if(i!=min)
		{
			temp=Seq[i];
			Seq[i]=Seq[min];
			Seq[min]=temp;
			SwapCount++;
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d",Seq[i]);
		printf("%c",i==N-1?'\n':' ');
	}
	printf("%d\n",SwapCount);
	
}
