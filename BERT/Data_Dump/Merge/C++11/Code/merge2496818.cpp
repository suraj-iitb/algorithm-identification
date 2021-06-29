#undef		FILE_INPUT_DEFINE
#ifdef		FILE_INPUT_DEFINE
#include	<fstream>
#endif		// FILE_INPUT_DEFINE

#include	<iostream>
#include	<climits>			//INT_MAX

using namespace std;

#define		MAX		500000

int		S[MAX + 1];
int		L[MAX / 2 + 1];
int		R[MAX / 2 + 1];
int		Compare = 0;

void merge(int A[], int left, int mid, int right)
{
	int		n1 = mid - left;
	int		n2 = right - mid;

	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[mid + i];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int	i = 0;
	int	j = 0;

	for (int k = left; k < right; ++k)
	{
		++Compare;
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			++i;
		}
		else
		{
			A[k] = R[j];
			++j;
		}
	}
}

void mergeSort(int A[], int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
#ifdef		FILE_INPUT_DEFINE
	// input from txt
	std::ifstream in(R"(C:\Temp\input.txt)");
	std::cin.rdbuf(in.rdbuf());
#endif		// FILE_INPUT_DEFINE

	int		n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> S[i];
	}

	mergeSort(S, 0, n);

	for (int i = 0; i < n; ++i)
	{
		if (i != 0)			cout << " ";
		cout << S[i];
	}
	cout << "\n" << Compare << "\n";

	return 0;
}
