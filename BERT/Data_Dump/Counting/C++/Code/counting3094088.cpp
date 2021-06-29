#include<iostream>
using namespace std;
void countingSort(int A[], int n, int B[], int range)
{
	int *cnt = new int[range + 1]{ 0 };
	for (int i = 1; i <= n; i++)
		cnt[A[i]]++;
	for (int i = 1; i <= range; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; i--)
	{
		B[cnt[A[i]]] = A[i];
		cnt[A[i]]--;
	}
	delete[] cnt;
}
int main()
{
	int n;
	cin >> n;
	int range = 10000;
	int *A = new int[n + 1];
	int *B = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	countingSort(A, n, B, range);
	for (int i = 1; i <= n; i++)
		if (i != n)
			cout << B[i] << " ";
		else
			cout << B[i] << endl;
	delete[] A;
	delete[] B;
}
