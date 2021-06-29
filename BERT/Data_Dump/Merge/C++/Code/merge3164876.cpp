#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define INFTY 1000000001

int compnum = 0;

void merge(vector<int> &A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> L(n1 + 1);
	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	vector<int> R(n2 + 1);
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = INFTY;
	R[n2] = INFTY;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++){
		compnum++;
		if (L[i] <= R[j]){
			A[k] = L[i];
			i = i + 1;
		}
		else{
			A[k] = R[j];
			j = j + 1;
		}
	}

}

void mergeSort(vector<int> &A, int left, int right){
	if (left + 1 < right){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){

	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];

	mergeSort(A, 0, n);

	for (int i = 0; i < n; i++) cout << ((i != 0) ? " " : "") << A[i];
	cout << endl << compnum << endl;

	return 0;
}
