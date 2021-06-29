#include<stdio.h>
#define Number 100000
int main()
{
	int n;
	int c=0;
	int Sel[Number];
	int i ,j ,minj ,z;
	int temp;


	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&Sel[i]);
	}

	for(i=0;i<=n-1;i++)
	{
		minj=i;
		for(j=i;j<=n-1;j++)
		{
			if (Sel[j] < Sel[minj])
			{	
				minj=j;
			}	
		}
		if(minj!=i)
		{
		temp=Sel[minj];
		Sel[minj]=Sel[i];
		Sel[i]=temp;	
		c++;
		
	    }
	}

		for(z=0;z<n-1;z++)
	{
		printf("%d ",Sel[z]);
	}
		printf("%d\n",Sel[n-1]);
	printf("%d\n",c);

	}
