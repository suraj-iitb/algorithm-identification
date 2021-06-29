#include<iostream>
using namespace std;
void printArray(int a[],int length)
{
	for (int i = 0; i < length - 1; ++i)
		cout << a[i] << " ";
	cout << a[length-1];
	cout << endl;

}
void insertionSort(int a[], int length)
{
	printArray(a, length);
	for (int i = 1; i <= length - 1; ++i)
	{
		int num = a[i];
		int j;
		for (j = i-1; j >=0&& num < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = num;
		printArray(a, length);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	insertionSort(a, n);
	delete[]a;
	return 0;
}
