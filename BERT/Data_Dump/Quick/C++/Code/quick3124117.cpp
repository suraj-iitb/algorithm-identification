#include<iostream>
using namespace std;
#define max 500000
#define infty 2000000000



struct Card{
	char key;
	int value;
};

int partition(Card A[], int p, int r){
	Card x;
	int j = p-1;
	x = A[r];
	for(int i = p; i < r; i++){
		if(A[i].value <= x.value){
			j++;
			swap(A[j], A[i]);
		}
	}
	swap(A[j+1], A[r]);
	return j+1;
}

void q_sort(Card A[], int p, int r){
	int qs;
	if(p < r){
		qs = partition(A, p, r);
		q_sort(A, p, qs-1);
		q_sort(A, qs+1, r);
	}

}

void merge(Card A[], int left, int mid, int right){
	int nl = mid - left;
	int nr = right - mid;
	Card L[nl + 1], R[nr + 1];
	for(int i = 0; i < nl; i++) L[i] = A[left + i];
	for(int i = 0; i < nr; i++) R[i] = A[mid + i];
	L[nl].value = R[nr].value = infty;

	int j = 0, k = 0;
	for(int i = left; i < right; i++){
		if(L[j].value <= R[k].value){
			A[i] = L[j++];
		} 
		else{
			A[i] = R[k++];
		}
	}
}

void mergeSort(Card A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(void){
	int n, v;
	char k;
	cin >> n;
	Card A[n], B[n];
	for(int i = 0; i < n; i++){
		cin >> k >> v;
		A[i].key = B[i].key = k;
		A[i].value = B[i].value = v;
	}

	q_sort(A, 0, n-1);
	mergeSort(B, 0, n);
	int judge = 1;
	for(int i = 0; i < n; i++){
		if(B[i].key != A[i].key || B[i].value != A[i].value){
			judge = 0;
		}
	}
	if(judge == 1){
		cout << "Stable" << endl;
	}
	else{
		cout << "Not stable" << endl;
	}
	for(int i = 0; i < n; i++){
		cout << A[i].key << ' ' << A[i].value << endl;

	}
	return 0;
}
