#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i,p,b,count=0,j;
	
	scanf("%d", &p);
	int *binary = (int*)malloc(sizeof(int)*p);

	for (i = 0; i < p; i++)
	{
		scanf("%d", &binary[i]);
	}

    scanf("%d", &b);
	int *binary2 = (int*)malloc(sizeof(int)*b);

	for (i = 0; i < b; i++)
	{
		scanf("%d", &binary2[i]);
	}

	


	for (i = 0; i < b; i++)
	{
		int left = 0, right = p;
		
				while(left < right){
					j = (left + right) / 2;
					if(binary2[i] == binary[j])
					{
						count++;
					    break;
						
					}
					else if(binary2[i] > binary[j])
					left = j + 1;
					else if(binary2[i] < binary[j])
					right = j ;
				}
	
	}

	
		
	
	printf("%d\n", count);


	return 0;
}
