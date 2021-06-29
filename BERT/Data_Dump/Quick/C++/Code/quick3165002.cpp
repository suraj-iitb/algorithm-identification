#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define INFTY 1000000001

struct card{
	int n;
	char suit;
};

void swap(card &a, card &b){
	card x = a;
	a = b;
	b = x;
	return;
}

int partition(vector<card> &A, int p, int r){
	int x = A[r].n;
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (A[j].n <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(vector<card> &A, int p, int r){
	if (p < r){
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
	return;
}


void merge(vector<card> &A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	vector<card> L(n1 + 1);
	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	vector<card> R(n2 + 1);
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1].n = INFTY;
	R[n2].n = INFTY;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++){
		if (L[i].n <= R[j].n){
			A[k] = L[i];
			i = i + 1;
		}
		else{
			A[k] = R[j];
			j = j + 1;
		}
	}

}

void mergeSort(vector<card> &A, int left, int right){
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
	vector<card> A(n), B(n);
	for (int j = 0; j < n; j++){
		cin >> A[j].suit >> A[j].n;
		B[j] = A[j];
	}

	quicksort(A, 0, n - 1);
	mergeSort(B, 0, n);

	bool isStable = true;
	for (int j = 0; j < n; j++){
		if (A[j].suit != B[j].suit){
			isStable = false;
			break;
		}
	}
	cout << (isStable ? "Stable" : "Not stable") << endl;

	for (int j = 0; j < n; j++) cout << A[j].suit << " " << A[j].n << endl;

	return 0;
}
