#include<iostream>
using namespace std;
#define max 500000
#define infty 2000000000


int cnt;

void merge(int A[], int left, int mid, int right){
	int nl = mid - left;
	int nr = right - mid;
	int L[nl + 1], R[nr + 1];
	for(int i = 0; i < nl; i++) L[i] = A[left+i];
	for(int i = 0; i < nr; i++) R[i] = A[mid+i];
	L[nl] = R[nr] = infty;

	int j = 0, k = 0;
	for(int i = left; i < right; i++){
		cnt++;
		if(L[j] < R[k]){
			A[i] = L[j++];
		}
		else{
			A[i] = R[k++];
		}
	}
}

void mergeSort(int A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(void){
	int A[max], n;
	cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	mergeSort(A, 0, n);
	for(int i = 0; i < n; i++){
		if(i == n-1){
			cout << A[i] << endl;
		}
		else{
			cout << A[i] << ' ';
		}
	}
	cout << cnt << endl;

	return 0;
}
