#include <iostream>
using namespace std;
#define MAX_N 100
int selection_sort(int *arr, int size)
{
	int step = 0;
	for (int i = 0; i < size; i++)
	{
		int mini = i;
		for (int j = i; j < size; j++)
		{
			if (arr[j] < arr[mini])
			{
				mini = j;
			}
		}
		if (mini != i)
		{
			int temp = arr[i];
			arr[i] = arr[mini];
			arr[mini] = temp;
			step++;
		}
	}

	return step;
}
int main()
{
	int n;
	cin >> n;
	int arr[MAX_N];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int step = selection_sort(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << arr[n - 1] << endl << step << endl;
	return 0;
}
