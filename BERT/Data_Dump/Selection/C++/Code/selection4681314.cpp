#include <iostream>
using namespace std;

int Selection_sort(int A[], int N)
{
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		int	mini = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[mini])
			{
				mini = j;
			}
		}
		if (i != mini)
		{
			swap(A[i], A[mini]);
			c++;
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
	
	int c = Selection_sort(A, N);
	cout << c << endl;
}


