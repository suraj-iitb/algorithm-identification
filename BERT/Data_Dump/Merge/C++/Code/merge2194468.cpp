#include <iostream>
using namespace std;
const int INFTY = 1000000000;
int cnt = 0;

void merge(int A[],int left,int mid,int right) {
	int n1, n2;
	int *L, *R;
	n1 = mid - left;
	n2 = right - mid;
	L = new int[n1 + 1];
	R = new int[n2 + 1];
	for(int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for(int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	L[n1] = INFTY;
	R[n2] = INFTY;
	int i = 0;
	int j = 0;
	for (int k = left; k < right ; k++) {
		if( L[i] <= R[j]) {
			A[k] = L[i++];
			cnt++;
		}
		else { 
			A[k] = R[j++];
			cnt++;
		}
	}
	delete [] L;
	delete [] R;
}

void mergeSort(int A[], int left, int right) {
	int mid;
	if (left+1 < right) {
		mid = (left + right)/2;
		mergeSort(A,left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
int main () {
	int n;
	int* A;
	cin >> n;
	A = new int[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	mergeSort(A, 0, n);
	for(int i = 0; i < n - 1; i++)
		cout << A[i] << ' ';
	cout << A[n - 1] << endl
		 << cnt << endl;
	return 0;
}
