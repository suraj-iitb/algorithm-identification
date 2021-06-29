#include <iostream>
using namespace std;
#define Nmax 500000
#define INF 1000000001

int a[Nmax];
int L[Nmax / 2 + 2];
int R[Nmax / 2 + 2];
int cnt;

void merge(int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[mid + i];
	}
	L[n1] = INF;
	R[n2] = INF;

	int i, j;
	i = j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int left, int right)
{
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cnt = 0;
	mergeSort(0, n);

	for (int i = 0; i < n; i++) {
		cout << a[i];
		cout << ((i != (n - 1)) ? " " : "\n");
	}
	cout << cnt << endl;

	return 0;
}
