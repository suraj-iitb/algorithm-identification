#include <iostream>
#define MAX 500000
#define INFINITY 2000000000
using namespace std;

int cnt = 0;
int arr[MAX];

void print(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << arr[i];
	}
}

void merge(int arr[], int left, int mid, int right)
{
	//right是数组最后一个位置的下一个 
	int n1 = mid - left;	//左边元素的个数,不包括mid,从0~mid-1 
	int n2 = right - mid;	//右边元素的个数,mid~right-1
	
	int L[n1], R[n2];	//将来自上一层的数组一分为二（其中，左右两边分别有序）
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left+i];	
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid+i];
	}
	
	//标记，用于简化算法 
	L[n1] = INFINITY;
	R[n2] = INFINITY;
	
	//test-def
//	printf("n1: ");
//	print(L, n1);
//	printf("\nn2: ");
//	print(L, n2);
//	printf("\n\n");
	//test-end
	
	//归并为一个有序数组，放入上层数组中 
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
	
	//test-def
//	printf("n1: ");
//	print(L, n1);
//	printf("\nn2: ");
//	print(L, n2);
//	printf("\n\n");
	//test-end
}

void MergeSort(int arr[], int left, int right)
{
	//至少有两个元素 arr[left],arr[left+1]
	//(arr[right]为最后一个元素的下一个，已越界) 
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid, right);
		merge(arr, left, mid, right);
	}
}



int main(void)
{

	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	MergeSort(arr, 0, n);
	print(arr, n);
	cout << endl << cnt << endl;
	
	return 0;
 } 
