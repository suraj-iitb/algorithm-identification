#include <stdio.h>
void printfArray(int Arr[],int length) {
	for (int i = 0;i < length;i++) {
		printf("%d",Arr[i]);
		if (i != length - 1) {
			printf(" ");
		}
	}
	printf("\n");
}
void InsertionSort(int nums[],int length) {
	printfArray(nums, length);
	for (int i = 1;i < length;i++) {
		//待排序元素;
		int cur = nums[i];
		int j = i-1;
		for (j;j >= 0 && nums[j] > cur;j--) {
			//元素后移;
			nums[j + 1] = nums[j];
		}
		//插入待排序元素元素;
		nums[j + 1] = cur;
		printfArray(nums, length);
	}
	
}
int main(){
	int length;
	scanf("%d", &length);
	int arr[100];
	for (int i = 0;i < length;i++) {
		scanf("%d", &arr[i]);
	}
	InsertionSort(arr, length);
	return 0;
}

