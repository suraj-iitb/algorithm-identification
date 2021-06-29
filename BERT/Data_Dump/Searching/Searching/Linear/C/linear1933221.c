#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i,p,b,count=0,j;
	
	scanf("%d", &p);
	int *linear = (int*)malloc(sizeof(int)*p);

	for (i = 0; i < p; i++)
	{
		scanf("%d", &linear[i]);
	}

    scanf("%d", &b);
	int *linear2 = (int*)malloc(sizeof(int)*b);

	for (i = 0; i < b; i++)
	{
		scanf("%d", &linear2[i]);
	}

	for (i = 0; i < b; i++)
	{
		for (j = 0; j < p; j++)
		{
			if (linear[j] == linear2[i])
			{
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);


	return 0;
}

// 
