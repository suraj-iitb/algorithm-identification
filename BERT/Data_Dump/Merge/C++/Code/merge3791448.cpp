#include<cstdio>
#include<iostream>
using namespace std;
const int MAXM=500000+7;
const int INF = 1e9 + 9;
int A[MAXM];
int L[MAXM];
int R[MAXM];
int cmp_count;
void merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++){
		L[i] = A[left+i];
	} 
	for(int i = 0; i < n2; i++){
		R[i] = A[mid+i];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0;
	int j = 0;
	int k;
	for(k = left; k < right; k++){
		cmp_count++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
}
void mergeSort(int A[], int left, int right){
	int mid;
	if(left+1<right){
		mid = (left+right)/2;
		mergeSort(A, left, mid);
		mergeSort(A	, mid, right);
		merge(A, left, mid, right);
	}
} 
int main() {
	cmp_count = 0;
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	mergeSort(A, 0, n);
	for(int i = 0; i < n; i++){
		if(i!=0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cmp_count << endl;
	
	return 0;
}
