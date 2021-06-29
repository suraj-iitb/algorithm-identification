#include <bits/stdc++.h>
using namespace std;
int a[500001];
int cnt = 0;

void merge1(int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;

	int* l;
	l=new int[n1+1] ;
	int* r;
	r = new int[n2+1];
	
	for (int i = 0; i < n1; i++) {
		l[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		r[i] = a[mid + i];
	}
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = left; k < right ; k++) {
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
void mergeSort(int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge1(left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	
	mergeSort(0,n);
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout <<" "<< a[i];
	}

	cout <<endl<< cnt<<endl;
	
	return 0;
}


