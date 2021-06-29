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
int SelectionSort(int nums[],int length) {
	//交换元素次数;
	int times = 0;
	//外层循环控制要交换元素的位置;
	for (int i = 0;i < length-1;i++) {
		//是否交换;
		int swap = 0;
		//最小值下标;
		int min = i;
		//从剩余的序列中找到最小的值;
		for (int j = i + 1;j < length;j++) {
			//如果待排序序列中包含了比当前最小值还小的,则将其下标设置为最小值下标;
			if (nums[j]<nums[min]) {
				min = j;
				swap = 1;
			}
		}
		if (swap) {
			//序列遍历结束,交换元素;
			int temp = nums[min];
			nums[min] = nums[i];
			nums[i] = temp;
			times++;
		}
	}
	printfArray(nums,length);
	return times;
}
int main(){
	int length;
	scanf("%d", &length);
	int arr[100];
	for (int i = 0;i < length;i++) {
		scanf("%d", &arr[i]);
	}
	int times = SelectionSort(arr, length);
	printf("%d\n",times);
	return 0;
}

