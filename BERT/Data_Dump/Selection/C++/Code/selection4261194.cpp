#include <iostream>
#include <time.h>

using namespace std;

template<typename T>
void Print(const T* pArray, int size)
{
	for (int i = 0; i < size; ++i)
		cout << pArray[i] << (i != size - 1 ? " " : "\n");
}

template<typename T>
void SelectionSort(T* pArray, int size, int& count)
{
	T temp;
	int minIndex;
	for (int i = 0; i < size - 1; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (pArray[j] < pArray[minIndex])
				minIndex = j;
		}

		if (i != minIndex)
		{
			temp = pArray[i];
			pArray[i] = pArray[minIndex];
			pArray[minIndex] = temp;
			++count;
		}
	}
}

int main()
{
	int n; cin >> n;
	int* pArray = new int[n];
	for (int i = 0; i < n; ++i) cin >> pArray[i];

	int count = 0;
	SelectionSort(pArray, n, count);
	Print(pArray, n);
	cout << count << endl;
}
