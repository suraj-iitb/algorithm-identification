#include<iostream>
using namespace std;
const int INF = 999999999;
const int MAX = 500000;
int cnt = 0;
int A[MAX], L[MAX], R[MAX];
void merge(int A[], int left, int mid, int right)
{
	int ln = mid - left;
	int rn = right - mid;
	for (int i = 0; i < ln; i++)
		L[i] = A[left + i];
	for (int i = 0; i < rn; i++)
		R[i] = A[mid + i];
	L[ln] = R[rn] = INF;
	int i = 0, j = 0;
	for (int k = left; k < right; k++)
	{
		cnt++;
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}
void mergeSort(int A[], int left, int right)
{
	if (left+1 >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid, right);
	merge(A, left, mid, right);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	mergeSort(A, 0, n);
	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	cout << cnt << endl;
}
