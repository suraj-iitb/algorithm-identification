#include <iostream>
#include <limits>

#define INFTY 1000000000
using namespace std;



int n;
int cnt=0;

void printArray(int* A){
	for(int i=0; i<n; i++){
		cout << A[i];
		if(i < n-1)
			cout << " ";
	}
	cout << endl;
}

void merge(int* A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;

	int L[n1+1], R[n2+1];
	for(int i=0; i<n1; i++)
		L[i] = A[left+i];
	for(int i=0; i<n2; i++)
		R[i] = A[mid+i];
	L[n1] = INFTY; R[n2] = INFTY;
	int i=0, j=0;
	for(int k=left; k < right; k++){
		if(L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
		cnt++;
	}
//	printArray(A);
}

void mergeSort(int* A, int left, int right){
	if(left + 1 < right){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	cin >> n;
	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];
	mergeSort(A, 0, n);
	printArray(A);
	cout << cnt << endl;

	return 0;
}
