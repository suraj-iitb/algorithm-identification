#include<iostream>
using namespace std;
const int MAX = 500000;

int L[MAX], R[MAX], A[MAX], n;
int num = 0;

void merge(int left, int mid, int right) 
{
	int n1 = mid - left;
	int n2 = right - mid - 1;

	for (int i = 0; i <= n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i <= n2; i++)
		R[i] = A[mid + 1 + i];

	L[n1 + 1] = R[n2 + 1] = (int)2e9;

	int i = 0, j = 0;
	for (int k = left; k <= right; k++)
	{
		num++;
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void MergeSort(int left, int right) 
{
	if (left < right) 
	{
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	MergeSort(0, n - 1);

	for (int i = 0; i < n - 1; i++)
		cout << A[i] << " ";
	cout << A[n - 1] << endl;

	cout << num << endl;
	return 0;
}
