#include <stdio.h>
int main(void)
{
	int n,i,j,v,k;
	scanf("%d", &n);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);//配列の中身の入力
	}
	for(i=0;i<n;i++)
	{
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v)
		{
			A[j+1] = A[j];
			j--;
		}
			A[j+1]=v;
		for(k=0;k<n;k++)
			{
				printf("%d",A[k]);
				if(k==n-1)
				{
					break;
				}
				printf(" ");
			}
			printf("\n");
	}	
}
