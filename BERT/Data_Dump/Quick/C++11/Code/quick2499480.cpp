//#define		FILE_INPUT_DEFINE
#ifdef		FILE_INPUT_DEFINE
#include	<fstream>
#endif		// FILE_INPUT_DEFINE

#include	<iostream>
#include	<deque>
#include	<string>
#include	<unordered_map>

using namespace std;

#define		MAX		100000
struct SN
{
	char	S;
	int		N;
};

SN					A[MAX];

void swap(int a, int b)
{
	SN		temp(A[a]);

	A[a] = A[b];
	A[b] = temp;
}

int		Partition(int p, int r)
{
	int		x = A[r].N;
	int		i = p - 1;

	for (int j = p; j < r; ++j)
	{
		if (A[j].N <= x)
		{
			i = i + 1;
			swap(i, j);
		}
	}

	swap(i + 1, r);

	return (i + 1);
}

void QuickSort(int p, int r)
{
	if (p < r)
	{
		int	q = Partition(p, r);
		QuickSort(p, q - 1);
		QuickSort(q + 1, r);
	}
}

int main()
{
#ifdef		FILE_INPUT_DEFINE
	// input from txt
	std::ifstream in(R"(C:\Temp\input.txt)");
	std::cin.rdbuf(in.rdbuf());
#endif		// FILE_INPUT_DEFINE

	int					n;
	cin >> n;
	unordered_map<int, string>	um;
	unordered_map<int, string>	um2;
	deque<int>			dq;

	for (int i = 0; i < n; ++i)
	{
		cin >> A[i].S >> A[i].N;
		cin.clear();
		cin.ignore();

		um[A[i].N] += A[i].S;
	}

	QuickSort(0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		um2[A[i].N] += A[i].S;
	}

	bool	isStable = true;
	for (auto it : um)
	{
		if (it.second != um2[it.first])
		{
			isStable = false;
			break;
		}
	}

	if (isStable)
	{
		cout << "Stable\n";
	}
	else
	{
		cout << "Not stable\n";
	}

	for (int i = 0; i < n; i++)
	{
		cout << A[i].S << " " << A[i].N << "\n";
	}

	return 0;
}
