#include<stdio.h>

#define NUMBER 100

void print_array(int array[],int num)
{
	int i;
	
	for(i = 0; i < num - 1; i++)
	{
		printf("%d ", array[i]);
	}
	
	printf("%d\n",array[i]);
}

void insertSort(int array[],int num)
{
	int i, v, j;
	for(i = 1; i <= num - 1; i++)
	{
		print_array(array,num);
		
		v = array[i];
		j = i - 1;
		
		while(j >= 0 && array[j] > v)
		{
			array[j + 1] = array[j];
			j--;
		}
		
		array[j + 1] = v;
    }
}
	
int main(void)
{
	int i, num;
	int array[NUMBER];

	scanf("%d", &num);
	
	for(i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}
	
	insertSort(array , num);
	
	print_array(array , num);
	
	return 0;
}
