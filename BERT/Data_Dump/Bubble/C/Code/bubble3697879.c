#include<stdio.h>

int BubbleSort(int A[],int N);
void Show(int A[],int N);

int BubbleSort(int A[],int N)
{
	int j,flag=1,sum=0;
	while(flag)
	{
		flag=0;
		for(j=N-1;j>0;j--)
		{
			if(A[j]<A[j-1])
			{
				int temp;
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
				flag=1;
				sum++;
			}
		}
	}
	return sum;	
}

void Show(int A[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(i>0)
		    printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}

int main()
{
	int N,A[200],i,sum;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	sum=BubbleSort(A,N);
	Show(A,N);
	printf("%d\n",sum);
	return 0;
} 
