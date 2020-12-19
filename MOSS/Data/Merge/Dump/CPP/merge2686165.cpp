#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int a[500000] = { 0 },cnt=0;

void merge(int left, int mid, int right)
{
	int i, j;
	int n1 = mid - left;
	int n2 = right - mid;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	for (i = 0; i != n1; ++i)
	{
		L[i] = a[left + i];
	}
	for (i = 0; i != n2; ++i)
	{
		R[i] = a[mid + i];
	}
	L[n1] = R[n2] = 1000000001;
	i = j = 0;

	for (int k = left; k != right; ++k)
	{
		++cnt;
		if (L[i] > R[j])
		{
			a[k] = R[j];
			++j;
		}
		else
		{
			a[k] = L[i];
			++i;
		}
	}
	delete []L;
	delete []R;
}


void mergeSort(int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}


int main()
{
	int n;
	

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}

	mergeSort(0, n);

	for (int i = 0; i != n; ++i)
	{
		if (i)
		{
			cout << " ";
		}
		cout<< a[i];
	}
	cout << endl << cnt << endl;

	return 0;

}
