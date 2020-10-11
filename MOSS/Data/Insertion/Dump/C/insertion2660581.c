#include<stdio.h>


void printNums(int nums[], int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("%d\n", nums[length - 1]);
}

int main(){

	int length;
	scanf("%d", &length);

	int i, nums[length];
	for(i = 0; i<length ; i++)
	{
		scanf("%d", &nums[i]);
	}
	
	printNums(nums, length);

	int v, j;
	for(i=1;i<length;i++)
	{
		v = nums[i];
		j = i-1;
		while(j>=0 && nums[j] > v)
		{
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1] = v;

		printNums(nums, length);
	}

	return 0;
}
