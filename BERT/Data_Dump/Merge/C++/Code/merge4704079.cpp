#include <iostream>
#define MAX 500010
using namespace std;

int count = 0;

void Merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1], R[n2+1];
	for (int i = 0;i < n1;i++)
	{
		L[i] = A[left+i];
	}
	for (int i = 0;i < n2;i++)
	{
		R[i] = A[mid+i];
	}
	L[n1] = 1e+9;
	R[n2] = 1e+9;
	int i = 0, j = 0;
	
	for (int k = left;k < right;k++)
	{
		if (L[i] <= R[j] && i < n1)
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		count++;
	}
	
}

void Merge_Sort(int A[], int left, int right)
{
	int mid = 0;
	if (left+1 < right)
	{
		mid = (left + right) / 2;
		Merge_Sort(A, left, mid);
		Merge_Sort(A, mid, right);
		Merge(A, left, mid, right);
	}
	return;
}

int main ()
{
	int n, S[MAX];
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> S[i];
	}
	
	Merge_Sort(S, 0, n);
	
	cout << S[0];
	for (int i = 1;i < n;i++)
	{
		cout << " " << S[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}
