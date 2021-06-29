#include<iostream>
using namespace std;

#define max 500000
#define maxsize 2000000000
int cunt;
int L[max / 2 + 2], R[max / 2 + 2];

void merge(int A[], int n, int left, int mid, int right)
{
	int i, j;
	int n1, n2;
	n1 = mid-left;
	n2 = right-mid;
	for (i = 0; i < n1; i++)L[i]=A[left+i];
	for (i = 0; i < n2; i++)R[i] = A[mid+i];
	L[n1] = R[n2] = maxsize;
	i = 0; j = 0;
	for (int k = left; k < right; k++)
	{	
		cunt++;
		if (L[i] > R[j])
			A[k] = R[j++];
		else A[k] = L[i++];
	}
}

void mergesort(int A[], int n, int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergesort(A, n, mid, right);
		mergesort(A, n, left, mid);
		merge(A, n, left, mid, right);
	}
}

int main()
{
	int A[max], n, i;
	cunt = 0;

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];

	mergesort(A, n, 0, n);

	for (i = 0; i < n; i++)
	{
		if (i)cout << " ";
		cout << A[i];
	}

	cout << endl << cunt << endl;
	return 0;
}
