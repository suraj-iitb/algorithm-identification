#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int out(vector<int> &A,int n){
	int i;
	for (i=0;i<=n-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[n-1] <<endl;
}

int merge(vector<int> &A, int left, int mid, int right){
	int count=0;
	int n1=mid-left;
	int n2=right-mid;
	int i, j;
	vector<int> L(n1+1);
	vector<int> R(n2+1);
	for (i=0;i<=n1-1;i++){
		L[i]=A[left+i];
	}
	for (i=0;i<=n2-1;i++){
		R[i]=A[mid+i];
	}
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	i=0;
	j=0;
	int k;
	for (k=left;k<right;k++){
		count++;
		if (L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
	}
	
	return count;
}

int mergeSort(vector<int> &A, int left, int right){
	int count=0;
	if (left+1<right){
		int mid=(left+right)/2;
		count=mergeSort(A,left,mid)+mergeSort(A,mid,right)+merge(A,left,mid,right);
	}
	return count;
}
int main(){
	int n;
	int count=0;
	cin >> n;
	vector<int> A(n);
	int i;
	for (i=0;i<n;i++){
		cin >> A[i];
	}
	
	count=mergeSort(A,0,n);
	
	out(A,n);
	cout << count <<endl;
	return 0;
}
