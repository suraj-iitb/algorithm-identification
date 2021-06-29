#include<iostream>
#include<climits>
using namespace std;

struct card{
	char c; int x;
};

#define max 100000
struct card  L[max / 2 + 2], R[max / 2 + 2];

void merge(card A[], int n, int left, int mid, int right)
{
	int i, j;
	int n1, n2;
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++)L[i] = A[left + i];
	for (i = 0; i < n2; i++)R[i] = A[mid + i];
	L[n1].x = R[n2].x = INT_MAX;
	i = 0; j = 0;
	for (int k = left; k < right; k++)
	{
		if (L[i].x > R[j].x)
			A[k] = R[j++];
		else A[k] = L[i++];
	}
}

void mergesort(card A[], int n, int left, int right)
{
	if (left + 1 < right)    
	{
		int mid = (left + right) / 2;
		mergesort(A, n, mid, right);
		mergesort(A, n, left, mid);
		merge(A, n, left, mid, right);                      
	}
}

int partition(card A[], int p, int r)
{
	card x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j].x <= x.x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(card A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

bool comperation(card A[],card B[], int n)
{
	for (int i = 0; i < n; i++)
		if (A[i].c != B[i].c)
			return false;
	return true;
}

int main()
{
	card A[max], B[max];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i].c >> A[i].x;
		B[i] = A[i];
	}

	quicksort( B, 0, n - 1);
	mergesort(A, n, 0, n);

	if (comperation(A, B, n))cout << "Stable" << endl;
	else cout << "Not stable" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << B[i].c << " " << B[i].x << endl;
	}
	return 0;
}

