#include <stdio.h>

int main()
{
	int Seq[100],N,i,j,temp,countS=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&Seq[i]);
	for(i=0;i<N;i++)
		for(j=N-1;j>i;j--)
			if(Seq[j]<Seq[j-1])
			{
				temp=Seq[j];
				Seq[j]=Seq[j-1];
				Seq[j-1]=temp;
				countS++;
			}
	for(i=0;i<N-1;i++)
		printf("%d ",Seq[i]);		
	printf("%d\n%d\n",Seq[i],countS);
	return 0;
}
