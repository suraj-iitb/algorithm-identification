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
 * T objects must provide operator>  and operator=
 */
template<typename T>
void InsertionSort(T* pArray, int size)
{
	Print(pArray, size);
	T key;
	// [0]..[i][j]..[size-1]
	// 前面是有序数据, j表示无序数据最前一位的索引
	// 最初值i表示有序数据最后一位的索引，i = j - 1
	// 0到i是有序数据,j到size-1是无序数据
	for (int j = 1; j < size; ++j)//要插入的无序数据
	{
		// 将当前的无序数据插入到之前的有序数据中
		key = pArray[j];
		// 将当前的无序数据和之前的有序数据比较，插入到合适的位置
		int i = j - 1;
		while (i >= 0 && pArray[i] > key)
		{
			// 当前的无序数据比有序数小，
			// 将有序数据向后偏移1位
			pArray[i + 1] = pArray[i];
			--i;
		}

		pArray[i + 1] = key;
		Print(pArray, size);
	}
}

int main()
{
	int n; cin >> n;
	int* pArray = new int[n];
	for (int i = 0; i < n; ++i) cin >> pArray[i];

	InsertionSort(pArray, n);
	
	delete[] pArray;

	return 0;
}
