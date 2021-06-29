#include<iostream>
using namespace std;
#define INFTY (int)(1e9)

int c;

template<class T>
void merge(T A[], int left, int mid, int right){
	int n1 = mid - left, n2 = right - mid;
	T L[n1], R[n2];
	for(int i = 0; i < n1; i++){
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	// L[n1] = INFTY;
	// R[n2] = INFTY;
	for(int k = left, i = 0, j = 0; k < right; k++){
		c++;
		if(j == n2 || i != n1 && L[i] <= R[j]){
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

template<class T>
void mergeSort(T A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(A,left, mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(){
	int A[500010], n;
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>A[i];
	}
	
	mergeSort(A,0,n);
	
	for(int i = 0; i < n; i++){
		if(i)cout<<" ";
		cout<<A[i];
	}cout<<endl;
	
	cout<<c<<endl;
	
	return 0;
}
