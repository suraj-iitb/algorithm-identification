#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int count = 0;
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if (A[j] < A[j - 1])
			{
				swap(A[j], A[j - 1]);
				count++;
			}
	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	cout << count << endl;
	delete[] A;
}
