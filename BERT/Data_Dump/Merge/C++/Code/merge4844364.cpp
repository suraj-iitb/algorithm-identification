#include<iostream>
#include<vector>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000
int A[500000] = { 0 };
int num = 0;
int  L[MAX/2+2], R[MAX/2+2];
void merge(int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	L[n1] = R[n2] = SENTINEL;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		num++;
	}
}

void mergeSort(int left,int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(mid, right);
		mergeSort(left, mid);
		merge(left, mid, right);
	}

}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> A[i];
	mergeSort(0, n);
	for (int i = 0; i < n; i++) {
		if (i)cout << ' ';
		cout << A[i] ;
	}
	cout << '\n' << num<<'\n';
	return 0;
}
