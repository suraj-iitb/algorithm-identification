#include<iostream>
using namespace std;
#define SENTINEL 2000000000
int cnt = 0;
//my merge sort
/*void merge(int* arr, int left, int mid, int right) {
	int len1 = mid - left + 1;
	int len2 = right - mid;
	int* tempL = new int[len1];
	int* tempR = new int[len1];
	for (int i = 0; i < len1; i++) tempL[i] = arr[left + i];
	for (int i = 0; i < len2; i++)tempR[i] = arr[mid + 1 + i];
	int i = 0, j = 0;
	for (int k = left; k <= right; k++) {
		cnt++;
		if (i < len1 && (j >= len2 || tempL[i] <= tempR[j]))
			arr[k] = tempL[i++];
		else
			arr[k] = tempR[j++];
	}
	delete[]tempL;
	delete[]tempR;
}
void mergeSort(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	if (left < mid) {
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
	}
	merge(arr, left, mid, right);
}*/
//merge sort of the book
void merge(int* arr, int left,int mid, int right) {
	int len1 = mid - left;//one for infinate
	int len2 = right - mid;//right originally one for infinate
	int* L = new int[len1 + 1];
	int* R = new int[len2 + 1];
	for (int i = 0; i < len1; i++)L[i] = arr[left + i];
	for (int i = 0; i < len2; i++)R[i] = arr[mid + i];
	L[len1] = R[len2] = SENTINEL;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}
}
void mergeSort(int* arr, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid, right);
		merge(arr, left, mid, right);
	}
}
int main() {
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	//mergeSort(arr, 0, len-1);
	mergeSort(arr, 0, len);
	for (int i = 0; i < len; i++)
		if (i)
			cout << " " << arr[i];
		else
			cout << arr[i];
	cout << endl;
	cout << cnt << endl;
	delete[]arr;
	return 0;
}
