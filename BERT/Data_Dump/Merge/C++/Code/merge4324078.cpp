#include<iostream>
#include<algorithm>
using namespace std;
#define sentinel 1000000000
#define max 500000

int l[max/2 + 2];
int r[max/2 + 2];
int cnt;

void merge(int a[],int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int i;
	for (i = 0; i < n1; i++) {
		l[i] = a[left + i];
	}
	for (i = 0; i < n2; i++) {
		r[i] = a[mid + i];
	}
	l[n1] = sentinel;
	r[n2] = sentinel;
	i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (l[i] <= r[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
		}
		cnt++;
	}
}

void mergesort(int a[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergesort(a,left, mid);
		mergesort(a,mid, right);
		merge(a,left, mid, right);
	}
}

int main()
{
	int a[max];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergesort(a, 0, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}
