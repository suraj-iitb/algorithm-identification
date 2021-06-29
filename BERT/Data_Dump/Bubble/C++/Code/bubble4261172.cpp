#include <iostream>
#include <time.h>

using namespace std;

template<typename T>
void Print(const T* pArray, int size)
{
	for (int i = 0; i < size; ++i)
		cout << pArray[i] << (i != size - 1 ? " " : "\n");
}

/**
 * T objects must provide operator< and operator=
 */
template<typename T>
void BubbleSort(T* pArray, int size, int& count)
{
	T temp;
	// 前面是有序数据, j表示无序数据最前一位的索引
	// [0]..[i][j]..[size-1]
	// 0到i是有序数据,j到size-1是无序数据
	for (int i = 0; i < size - 1; ++i)
	{
		// 无序数据两两比较将当前的最值（最小值最大值）
		// 加入到有序数据中
		for (int j = size - 1; j > i; --j)
		{
			if (pArray[j] < pArray[j - 1])
			{
				temp = pArray[j - 1];
				pArray[j - 1] = pArray[j];
				pArray[j] = temp;
				++count;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* pArray = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> pArray[i];

	int count = 0;
	BubbleSort(pArray, n, count);
	Print(pArray, n);
	cout << count << endl;
	delete[] pArray;

	return 0;
}
