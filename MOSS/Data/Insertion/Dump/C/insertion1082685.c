#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int A[],int N);
void echo(int A[],int N);

int main()
{
	int N;
	scanf("%d",&N);
	
	int A[N];
	
	char str[1024];
	for(;1;)
	{
		fgets(str,sizeof(str),stdin);
		if(strcmp(str,"\n")!=0)
		{
			break;
		}
	}
	
	A[0]=atoi(strtok(str," "));
	
	int i;
	for(i=1;i<N;i++)
	{
		A[i]=atoi(strtok(NULL," "));
	}
	
	insertionSort(A,N);
	
	return 0;
}

void insertionSort(int A[],int N)
{
	int key,i,j;
	echo(A,N);
	for(i=1;i<N;i++)
	{
		key=A[i];
		j=i-1;
		while(j>=0 && A[j]>key)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		echo(A,N);
	}
}

void echo(int A[],int N)
{
	int i;
	for(i=0;i<N-1;i++)
	{
		printf("%d ",A[i]);
	}
	printf("%d\n",A[N-1]);
}
