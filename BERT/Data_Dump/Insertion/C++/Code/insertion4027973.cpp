#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];


	void print(int* a, int n);
	print(A, n);

	for (int i = 1; i < n; i++)
	{
		int temp = A[i];
		int j = i - 1;
		while (j >= 0 && temp < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
		print(A, n);
	

	}







	delete[] A;
	return 0;
}


void print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << a[i] << endl;
		else
			cout << a[i] << " ";
	}
}
