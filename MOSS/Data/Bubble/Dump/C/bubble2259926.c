// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdio.h"


int main()
{
	int i, j, temp,sum,sei[100],num=0;
	scanf("%d",&sum);

	for (i = 0; i < sum; i++)
	{
		scanf("%d",&sei[i]);
	}

	for (i = 0; i < sum; i++)
	{
		for (j = sum - 1; j > i; j--)
		{
			if (sei[j] < sei[j - 1])
			{
				temp = sei[j - 1];
				sei[j - 1] = sei[j];
				sei[j] = temp;
				num++;
			}
		}
	}

	for (i = 0;; i++)
	{
		printf("%d",sei[i]);
		if (i >= sum-1)break;
		printf(" ");
	}

	printf("\n%d\n",num);
    return 0;
}
