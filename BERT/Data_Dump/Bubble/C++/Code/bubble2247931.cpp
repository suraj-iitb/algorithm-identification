
#include <iostream>
using namespace std;

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != 0)cout << " ";
		cout << arr[i];
	}
	cout << endl;
}

void swap(int *arrA, int *arrB)
{
	int temp = *arrA;
	*arrA = *arrB;
	*arrB = temp;
}

int bubbleSort(int *arr, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] <  arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int arr[100];
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];

	int sortCnt = bubbleSort(arr, N);
	printArr(arr, N);
	cout << sortCnt << endl;
	
	return 0;
}
