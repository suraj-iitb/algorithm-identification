#include <iostream>
#define SENTINEL 1000000000
using namespace std;

void Merge(int left, int mid, int right);
void MergeSort(int left, int right);

int A[500000];
int count = 0;

int main(){

	int n;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	
	MergeSort(0,n);
	
	for(int i=0; i<n; i++){
		cout << A[i];
		if(i!=n-1){
			cout << " ";
		}
	}
	
	cout << "\n" << count << "\n";

}

void Merge(int left, int mid, int right){
	int n1, n2;
	
	n1 = mid - left;
	n2 = right - mid;
	
	int L[n1+1], R[n2+1];
	
	for(int i=0; i<n1; i++){
		L[i] = A[left+i];
	}
	for(int i=0; i<n2; i++){
		R[i] = A[mid+i];
	}
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	for(int i=0,j=0,k=left; k<right; k++){
		if(L[i] == SENTINEL && R[j] == SENTINEL) break;
		count++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
	
}

void MergeSort(int left, int right){
	
	int mid;
	if(left+1 < right){
		mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid, right);
		Merge(left, mid, right);
	}
	
}
