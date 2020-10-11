#include<stdio.h>

int selectionSort(int A[],int N);
void Show(int A[],int N);

int selectionSort(int A[],int N)
{
	int i,minj,sum=0,j;
	for(i=0;i<N;i++)
	{
		minj=i;
		for(j=i+1;j<N;j++)
			if(A[j]<A[minj])
				minj=j;
		int temp;
		if(minj!=i)
		{
			temp=A[i];
			A[i]=A[minj];
			A[minj]=temp;
			sum++;	
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
	sum=selectionSort(A,N);
	Show(A,N);
	printf("%d\n",sum);
	return 0;
} 
