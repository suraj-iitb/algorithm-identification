#include <iostream>
using namespace std;

void BubbleSort(int* arr,int num)
{
	for (int x = 0; x < num - 1; x++)
	{
		cout << arr[x] << " ";
	}
	cout << arr[num - 1];
	cout << endl;
	for (int i = 1; i < num; i++)
	{
		int key = arr[i];
		 int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		for (int x = 0; x < num - 1; x++)
		{
			cout << arr[x] << " ";
		}
		cout << arr[num - 1];
		cout << endl;
	}
}

int main()
{
	int num;
	cin >> num;
	int* arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	BubbleSort(arr, num);
	return 0;
}
