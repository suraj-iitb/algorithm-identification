#include <iostream>
#include <cstdlib>
#define INF 1000000000

using namespace std;

int merge(int *A, int left, int mid, int right){
	int cnt = 0;
	int n1 = mid-left;
	int n2 = right-mid;
	int *L = (int *)malloc(sizeof(int)*(n1+1));
	int *R = (int *)malloc(sizeof(int)*(n2+1));
	for(int i = 0; i < n1; i++) { L[i] = A[left+i]; }
	for(int i = 0; i < n2; i++) { R[i] = A[mid+i]; }
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for( int k = left; k < right; k++ ){
		cnt++;
		if( L[i] <= R[j] ){
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
	return cnt;
}

int mergeSort(int *A, int left, int right){
	int cnt = 0;
	if( left+1 < right ){
		int mid = (left+right)/2;
		cnt += mergeSort(A, left, mid);
		cnt += mergeSort(A, mid, right);
		cnt += merge(A, left, mid, right);
	}
	return cnt;
}

int main(){
	int *A, n, cnt = 0;
	
	cin >> n;
	A = (int *)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cnt = mergeSort(A, 0, n);
	
	for(int i = 0; i < n; i++) { 
		cout << A[i];
		if( i != n-1 ) cout << " ";
	}
	cout << endl;
	cout << cnt << endl;
	
	return 0;
}
