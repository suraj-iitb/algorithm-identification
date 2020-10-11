#include <stdio.h>
#include <stdlib.h>


int main()
{
	
	int i=0,p=0,t=0,flag=0,count=0;
	
	scanf("%d", &p);
	int *bubblesort = (int*)malloc(sizeof(int)*p);

	for (i = 0; i < p; i++)
	{
		scanf("%d", &bubblesort[i]);
	}
	
	
	
	flag = 1;
	while(flag)
	{
		flag = 0;
		for(i=p-1;i>0;i--)
		{
			if(bubblesort[i] < bubblesort[i-1])
			{
				 t = bubblesort[i];
				 bubblesort[i] = bubblesort[i-1];
				 bubblesort[i-1] = t;
				 count++;
				 flag = 1;
			}
		}
	}
	
	
	for(i=0;i<p;i++)
	{
		if(i==0){
			printf("%d",bubblesort[i]);
		}
		else{
			printf(" %d",bubblesort[i]);
		}
	}
	
	printf("\n");
	printf("%d\n",count);
	
	return 0;
	
	
}
