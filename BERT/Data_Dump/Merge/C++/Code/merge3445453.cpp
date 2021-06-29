#include <iostream>
using namespace std;

int N, T[500000], comp;

void Merge(int *A, int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	
	int L[n1 + 1], R[n2 + 1];
	for(int i = 0; i < n1; ++i)
	{
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; ++i)
	{
		R[i] = A[mid + i];
	}
	
	L[n1] = 1000000007, R[n2] = 1000000007;
	int i = 0, j = 0;
	for(int k = left; k < right; ++k)
	{
		++comp;
		if(L[i] < R[j])
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
	}
}

void MergeSort(int *A, int left, int right)
{
	if(left + 1 < right)
	{
		int mid = (left + right) / 2;
		MergeSort(A, left, mid);
		MergeSort(A, mid, right);
		Merge(A, left, mid, right);
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> T[i];
	}
	
	comp = 0;
	MergeSort(T, 0, N);
	
	for(int i = 0; i < N; ++i)
	{
		if(i != 0)
		{
			cout << " ";
		}
		
		cout << T[i];
	}
	cout << endl << comp << endl;

    return 0;
}

