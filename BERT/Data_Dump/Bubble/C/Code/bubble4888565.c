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
int Bubble(int nums[],int length){
	int times = 0;
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length - i - 1;j++) {
			//交换;
			if (nums[j]>nums[j+1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				//交换次数加一;
				times++;
			}
		}
	}
	printfArray(nums, length);
	return times;
}
int main(){
	int length;
	scanf("%d", &length);
	int arr[100];
	for (int i = 0;i < length;i++) {
		scanf("%d", &arr[i]);
	}
	int times = Bubble(arr, length);
	printf("%d\n", times);
	return 0;
}

