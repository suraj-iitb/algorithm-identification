#include	<cstdint>
#include	<iostream>
#include	<fstream>

typedef		std::uint_least32_t		ULI;		//10^9
typedef		std::int_least32_t		SLI;
typedef		std::uint_least64_t		ULLI;
typedef		std::int_least64_t		SLLI;

using namespace std;

int		Cnt = 0;

void Swap(int *a, int *b)
{
	int		temp = *a;
	*a = *b;
	*b = temp;
	Cnt++;
}

void SelectionSort(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		int		minj = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		if (i != minj)
		{
			Swap(&(A[i]), &(A[minj]));
		}
	}
}

int main()
{
	int		N;
	int		A[100];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	SelectionSort(A, N);

	for (int i = 0; i < N; i++)
	{
		if (i != 0)	cout << " ";
		cout << A[i];
	}
	cout << "\n";

	cout << Cnt << "\n";

	return 0;
}
