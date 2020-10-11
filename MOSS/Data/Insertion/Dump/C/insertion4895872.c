#include<stdio.h>
#define MAX_N 1000
void insertionsort(int A[MAX_N],int N)
{
	int i,v,j,k,l;
	for(i=0;i<N;i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v)
		{
		    A[j+1]=A[j];
		    j--;
		    A[j+1]=v;
		}
		 for(k=0;k<=N-1;k++)
		{
		    printf("%d",A[k]);
		    if(k!=N-1)
		    {
		        printf(" ");
		    }
		}
		printf("\n");
	}
}
int main(void)
{
    int A[MAX_N];
    int N;
    int i;
    scanf("%d",&N);
    for(i=0;i<=N-1;i++)
    {
        scanf("%d",&A[i]);
    }
    insertionsort(A,N);
	return 0;
}
