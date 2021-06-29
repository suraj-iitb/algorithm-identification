#include <iostream>
using namespace std;
#define DEKAI 2000000000
#define MAX 500000

int cnt;
int L[MAX/2+2],R[MAX/2+2];

void merge(int A[],int left,int mid,int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = DEKAI;
	int i = 0;
	int j = 0;
	for (int k = left; k < right ; ++k)
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

void mergesort(int A[],int left,int right)
{
	if (left+1 < right)
	{
		int mid = (left + right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main()
{
	int n,A[MAX];
	cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	mergesort(A,0,n);

	for (int i = 0; i < n; ++i)
	{
		if (i)
		{
			cout << " ";
		}
		cout << A[i];
	}

	cout << "\n" << cnt << "\n";
	return 0;
}
