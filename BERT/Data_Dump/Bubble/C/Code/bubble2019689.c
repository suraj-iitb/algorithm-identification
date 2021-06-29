#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) {int z; z = x; x = y; y = z;}

int bubbleSort(int *nums, int size)
{
	int i, j, swap_num = 0;

	for(i = size; 1 < i; i--) {
		for(j = 1; j < i; j++) {
			if(nums[j] < nums[j - 1]) {
				SWAP(nums[j], nums[j - 1]);
				swap_num++;
			}
		}
	}

	return swap_num;
}

void dispNums(int *nums, int size)
{
	int i;
	
	printf("%d", nums[0]);
	for(i = 1; i < size; i++)
		printf(" %d", nums[i]);
	printf("\n");
}

int main(void)
{
	int n, i, swap_num;
	int *nums;

	scanf("%d", &n);
	nums = malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", nums + i);
	swap_num = bubbleSort(nums, n);
	dispNums(nums, n);
	printf("%d\n", swap_num);
	return 0;
}
