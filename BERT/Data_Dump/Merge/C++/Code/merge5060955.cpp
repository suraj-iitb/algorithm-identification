#include <iostream>
#include <algorithm>
using namespace std;

const int  INFTY=2000000000;
const int MAX_N=500000;
int A[MAX_N];
int L[MAX_N/2+1], R[MAX_N/2+1];

int cnt;

void Marge(int A[], int n, int left, int mid, int right) {
	
	int n1=mid-left;
	int n2=right-mid;

	for (int i=0; i<n1; i++) L[i] = A[left+i];
	for (int i=0; i<n2; i++) R[i] = A[mid+i];
	L[n1] = R[n2] = INFTY;


	int i=0, j=0;
	for (int k=left; k<right; k++) {
		
		cnt++;

		if (L[i]<=R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

void Marge_sort(int A[], int n, int left, int right) {

	if (left+1<right) {
		int mid=(left+right)/2;

		Marge_sort(A, n, left, mid);
		Marge_sort(A, n, mid, right);
		Marge(A, n, left, mid, right);
	}
}

int main() {
	
	int n;
	

	cin >> n;
	for (int i=0; i<n; i++) cin >> A[i];

	cnt = 0;
	
	Marge_sort(A, n, 0, n);

	for (int i=0; i<n; i++) {
		if (i!=0) cout << ' ';
		cout << A[i];
	}
	cout << endl;

	cout << cnt << endl;

	return 0;
}
