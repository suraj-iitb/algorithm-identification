#include	<cstdint>
#include	<iostream>
#include	<fstream>

typedef		std::uint_least32_t		ULI;		//10^9
typedef		std::int_least32_t		SLI;
typedef		std::uint_least64_t		ULLI;
typedef		std::int_least64_t		SLLI;

using namespace std;

int	Cnt = 0;

void BubbleSort(int A[], int N);

int main()
{
	int		N;
	int		A[100];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	BubbleSort(A, N);

	for (int i = 0; i < N; i++)
	{
		if (i != 0)	cout << " ";
		cout << A[i];
	}
	cout << "\n";
	cout << Cnt << "\n";

	return 0;
}

void BubbleSort(int A[], int N)
{
	bool		flag = true;

	while (flag)
	{
		flag = false;

		for (int i = N - 1; i > 0; i--)
		{
			if (A[i] < A[i - 1])
			{
				int		temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				Cnt++;
				flag = true;
			}
		}
	}
}
