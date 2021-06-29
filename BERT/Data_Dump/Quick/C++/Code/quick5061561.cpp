#include <iostream>
#include <algorithm>
using namespace std;

const int INFTY=2000000000;
const int MAX_N=100000;


struct card {
	char letter;
	int number;
};

card L[MAX_N/2+2], R[MAX_N/2+2];


int partition(card A[], int p, int r) {

	card x=A[r];
	int i=p-1;

	for (int k=p; k<r; k++) {
		
		if (A[k].number<=x.number) {
			i++;
			swap(A[k], A[i]);
		}
	}
	swap(A[r], A[i+1]);

	return i+1;
}

void Quick_sort(card A[], int p, int r) {
	
	if (p<r) {
		int q=partition(A, p, r);
		Quick_sort(A, p, q-1);
		Quick_sort(A, q+1, r);
	}
}

void Marge(card A[], int n, int left, int mid, int right) {
	
	int n1=mid-left;
	int n2=right-mid;

	for (int i=0; i<n1; i++) L[i] = A[left+i];
	for (int i=0; i<n2; i++) R[i] = A[mid+i];
	R[n2].number = L[n1].number = INFTY;

	int i=0, j=0;
	for (int k=left; k<right; k++) {
		
		if (L[i].number<=R[j].number) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

void Marge_sort(card A[], int n, int left, int right) {
	
	if (left+1<right) {
		int mid=(left+right)/2;
		Marge_sort(A, n, left, mid);
		Marge_sort(A, n, mid, right);
		Marge(A, n, left, mid, right);
	}
}

int main() {

	int n;
	card A[MAX_N], B[MAX_N];

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> A[i].letter >> A[i].number;
		B[i].letter = A[i].letter;
		B[i].number = A[i].number;
	}

	Marge_sort(B, n, 0, n);
	Quick_sort(A, 0, n-1);

	bool T=true;

	for (int i=0; i<n; i++) {
		if (A[i].letter!=B[i].letter) 
			T=false;
	}

	if (!T) cout << "Not stable" << endl;
	else cout << "Stable" << endl;
	for (int i=0; i<n; i++) cout << A[i].letter << ' ' << A[i].number << endl;

	return 0;
}
