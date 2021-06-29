#include <iostream>
using namespace std;

#define ALEN 500001 
#define INF 1000000000;

long L[ALEN];
long R[ALEN];

int merge(long Arr[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int count = 0;

	for(int i = 0; i < n1; i++){
		L[i] = Arr[left + i];
	}
	for(int i = 0; i <n2; i++){
		R[i] = Arr[mid + i];
	}

	L[n1] = INF;
	R[n2] = INF;

	int i = 0;
	int j = 0;
	for(int k = left; k < right; k++){
		if(L[i] <= R[j]){
			Arr[k] = L[i];
			i = i + 1;
		}else{
			Arr[k] = R[j];
			j = j + 1;
		}
		count++;
	}
	return count;
}

int mergeSort(long arr[], int left, int right){
	int count = 0;
	if(left + 1 < right){
		int mid = (left + right)/2;
		count += mergeSort(arr, left, mid);
		count += mergeSort(arr, mid, right);
		count += merge(arr, left, mid, right);
	}
	return count;
}

void printArr(long arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if(i != n - 1){
			cout << ' ';
		}
	}
	cout << endl;
}

int main(){
	long n, arr[ALEN];
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int count = mergeSort(arr, 0, n);
	printArr(arr, n);
	cout << count << endl;
	return 0;
}
