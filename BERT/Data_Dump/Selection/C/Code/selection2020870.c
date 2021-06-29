#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) {int z; z = x; x = y; y = z;}

void dispNums(int *nums, int length)
{
		int i;

		printf("%d", nums[0]);
		for(i = 1; i < length; i++)
				printf(" %d", nums[i]);	
		printf("\n");
}

int selectionSort(int *nums, int length)
{
		int i, j, min_index, swap_num = 0;

		for(i = 0; i < length; i++) {
				min_index = i;
				for(j = i + 1; j < length; j++) {
						if(nums[j] < nums[min_index])
								min_index = j;
				}
				if(min_index != i) {
						SWAP(nums[i], nums[min_index]);
						swap_num++;
				}
		}

		return swap_num;
}

int main(void) 
{
		int n, i, swap_num;
		int *nums;

		scanf("%d", &n);
		nums = malloc(sizeof(int) * n);	
		for(i = 0; i < n; i++) {
				scanf("%d", nums + i);
		}
		swap_num = selectionSort(nums, n);
		dispNums(nums, n);
		printf("%d\n", swap_num);

		return 0;
}
