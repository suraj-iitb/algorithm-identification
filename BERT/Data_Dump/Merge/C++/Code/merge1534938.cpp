#include<iostream>
#include<cmath>
#define INF 1000000001
using namespace std;

int C = 0;
int merge(int A[], int left, int mid, int right) {

    int n1, n2, i, j, k;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1+1], R[n2+1];
    
    for (i = 0; i < n1; i++) {
	L[i] = A[left+i];
    }
    for (i = 0; i < n2; i++) {
	R[i] = A[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    i = 0;
    j = 0;
    for (k = left; k < right; k++) {
	if (L[i] <= R[j]) {
	    A[k] = L[i];
	    i++;
	    C++;
	}
	else {
	    A[k] = R[j];
	    j++;
	    C++;
	}
    }
    return C;
}

int mergeSort(int A[], int left, int right) {
    if (left+1 < right) {
	int mid = (left + right ) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid, right);
	return merge(A, left, mid, right);
    }
}

int main() {
    int n, i, left, right, res;
    cin >> n;
    int A[n];
    
    for (i = 0; i < n; i++) {
	cin >> A[i];
    }
    left = 0;
    right = n;
    res = mergeSort(A, left, right);
    
    for (i = 0; i < n; i++) {
	if (i != n-1) cout << A[i] << " ";
	else cout << A[i];
    }
    cout << endl;
    cout << res << endl;
}
