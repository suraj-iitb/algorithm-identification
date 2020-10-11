#include<stdio.h>

void bubbleSort(int A[], int N);

int main(void)
{
	int n=0, i=0;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	bubbleSort(a, n);
	
	return 0;
}

void bubbleSort(int A[], int N)
{
	int flag = 1, i=0, j, temp=0, c=0;
	
	while(flag == 1)
	{
		flag = 0;
		
		for(j=N-1; j>=1; j--)
		{
			if(A[j] < A[j-1])
			{
				/* A[j]とA[j-1]を交換*/
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				
				flag = 1;
				c++;
			}
			
			if(flag==1) //もし交換したならば
			{
				break;
			}
		}

	}
	
	for(i=0; i<N; i++)
	{
		if(i<N-1)
		{
			printf("%d ", A[i]);
		}
		else
		{
			printf("%d", A[i]);
		}
	}
	printf("\n%d\n", c);
}


