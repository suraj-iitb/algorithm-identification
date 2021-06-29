#include <iostream>
using namespace std;
void trace(int A[], int N)
{
	for (int i = 0; i < N; i++){
	    if (i > 0)
	        cout << " ";
		cout << A[i];
	}
	cout << "\n";
}

void Insertion_sort(int A[], int N)
{
	int v, j;
	for (int i = 1; i < N; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		trace(A, N);
	}
}
int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	trace(A,N);
	Insertion_sort(A,N);
}


