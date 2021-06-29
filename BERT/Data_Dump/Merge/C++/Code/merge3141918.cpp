#include<iostream>
#include<cstdio>
#define Max 1000000
#define maxi 100000000000
using namespace std;
int total = 0;
int A[Max], B[Max];

void mergesort(int A[Max], int left, int right)
{
	int n = right - left;
	int mid = (left + right) / 2;
	int n1 = mid - left;
	int n2 = right - mid;
	int a[Max], b[Max];
	for (int i = 0; i < n1; i++)
	{
		a[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = A[mid + i];
	}
	a[n1] = maxi;
	b[n2] = maxi;
	int m1 = 0, m2 = 0;
	for (int i = left; i < right; i++)
	{
		total++;
		if (a[m1] < b[m2])
			A[i] = a[m1++];
		else
			A[i] = b[m2++];
	}
}


void merge(int A[Max], int left, int right)
{
	if (left+1 < right)
	{
		int mid = (left + right) / 2;
		merge(A, left, mid);
		merge(A, mid, right);
		mergesort(A, left, right);
	}
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	merge(A, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n - 1)
			cout << ' ';
	}
	cout << endl;
	cout << total << endl;
	return 0;
}
