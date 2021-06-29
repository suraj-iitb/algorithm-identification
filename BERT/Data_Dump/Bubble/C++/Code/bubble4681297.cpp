#include <iostream>
using namespace std;

int Bubble_sort(int A[], int N)
{
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (A[j] < A[j-1])
			{
				swap(A[j], A[j-1]);
				c++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << "\n";
	return c;
}
int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	int c = Bubble_sort(A, N);
	cout << c << endl;
}


