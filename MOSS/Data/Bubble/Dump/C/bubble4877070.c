#include <stdio.h>
#include <stdlib.h>



void bubble_sort(int arr[], int len) {
	
	int i, j, k=0;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				k++;
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
	for (i = 0; i < len-1; i++)
		printf("%d ", arr[i]);
		
	printf("%d\n", arr[i]);
	printf("%d\n", k);
}


int main(int argc, char *argv[]) {
	int arr[100], len;
	int i;
	scanf("%d", &len);
	for(i = 0;i<len;i++)
		scanf("%d", &arr[i]);

	bubble_sort(arr, len); 
	
	return 0;
}
