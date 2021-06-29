#include <stdio.h>

//int Bubsort(int *x,int n);
void show(int *x,int n);

int main()
{
	int n;

	scanf("%d",&n);
	
	int i,j,temp;
	int num[10000];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}

	int cont=0;
	for (i = 0; i < n; ++i)
	{
		for (j = n-1; j > i; j--)
		{
			if (num[j-1]>num[j])
			{
			temp=num[j];
			num[j]=num[j-1];
			num[j-1]=temp;
			cont++;
			}
		}
	}

	show(num,n);
	printf("%d\n",num[n-1] );
	printf("%d\n",cont);

	return 0;

}

/*int Bubsort(int *x,int n){
	int i,j,temp;
	int cont=0;
	for (i = 0; i < n; ++i)
	{
		for (j = n-1; j > i; j--)
		{
			if (x[j-1]>x[j])
			{
			temp=x[j];
			x[j]=x[j-1];
			x[j-1]=temp;
			cont++;
			}
		}
	}
	return cont;
}*/

void show(int *x,int n){
	int i;
	for (i = 0; i < n-1; ++i)
	{
		printf("%d ", x[i]);
	}
}
	
