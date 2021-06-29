#include <iostream>
using namespace std;

void print(int A[], int N)
{
	int i;
	for (i = 0; i < N - 1; i++) cout << A[i] << " ";
	cout << A[i];
	cout << endl;
}



int selectionSort(int A[], int N)
{
	int cnt = 0;
	
	// i is sorted
	for (int i = 0; i < N; i++)
	{
		int minj = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[minj]) minj = j;
		}
		swap(A[i], A[minj]);
		if(i != minj) cnt++;
	}

	return cnt;
}



int main()
{
	int N, A[100];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int cnt = selectionSort(A, N);

	print(A, N);
	cout << cnt << endl;

    return 0;
}
