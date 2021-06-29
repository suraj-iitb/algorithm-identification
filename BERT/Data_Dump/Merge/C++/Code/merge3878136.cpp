//merge Sort
#include <iostream>
#define SENTINEL 2000000000
#define MAX 500000
using namespace std;

int R[MAX/2+2],L[MAX/2+2];
int cnt;

void merge(int *A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0;i<n1;i++)
		L[i]=A[left+i];
	for(int i=0;i<n2;i++)
		R[i]=A[mid+i];
	L[n1] = R[n2] = SENTINEL;//记住要设置边界为无穷大
	int i=0, j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i]<R[j])
			A[k]=L[i++];
		else
			A[k]=R[j++];
	} 
}

void mergeSort(int *A, int n, int left, int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	
	int n;
	cin>>n;
	int A[n];
	cnt=0;
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	mergeSort(A, n, 0, n);
	
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
	cout<<cnt<<endl;
	
	return 0;
} 
