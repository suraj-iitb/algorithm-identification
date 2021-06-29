#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Print(const T* pArray, int size)
{
	for (int i = 0; i < size; ++i)
		cout << pArray[i] << (i != size - 1 ? " " : "\n");
}

template<typename T>
void Merge(T* pArray, int left, int middle, int right, T* pLeftArray, T* pRightArray, const T& max, int& count)
{
	int ll = middle - left;
	int rl = right - middle;
	for (int i = 0; i < ll; ++i) pLeftArray[i] = pArray[left + i];
	for (int i = 0; i < rl; ++i) pRightArray[i] = pArray[middle + i];
	pLeftArray[ll] = max;
	pRightArray[rl] = max;

	int i = 0, j = 0;
	for (int k = left; k < right; ++k)
	{
		++count;
		if (pLeftArray[i] < pRightArray[j])
		{
			pArray[k] = pLeftArray[i];
			++i;
		}
		else
		{
			pArray[k] = pRightArray[j];
			++j;
		}
	}
}

/**
 * first range
 * left = 0, right = size : range from 0 to (size - 1)
 */
template<typename T>
void MergeSort(T* pArray, int left, int right, T* pLeftArray, T* pRightArray, const T& max, int& count)
{
	if (left + 1 < right)// have two number at least: left, left + 1
	{
		int middle = (left + right) >> 1;
		MergeSort(pArray, left, middle, pLeftArray, pRightArray, max, count);
		MergeSort(pArray, middle, right, pLeftArray, pRightArray, max, count);
		Merge(pArray, left, middle, right, pLeftArray, pRightArray, max, count);
	}
}

#define MAX 500000
int main()
{
	int n;
	cin >> n;
	int* A = new int[MAX];
	for (int i = 0; i < n; ++i) cin >> A[i];
	int* leftArray = new int[MAX + 1];
	int* rightArray = new int[MAX + 1];
	int count = 0;
	MergeSort(A, 0, n, leftArray, rightArray, 2000000000, count);
	Print(A, n);
	cout << count << endl;
	delete[] A;
	delete[] leftArray;
	delete[] rightArray;

	return 0;
}
