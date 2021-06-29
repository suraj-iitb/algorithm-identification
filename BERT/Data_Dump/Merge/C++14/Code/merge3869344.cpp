//merge sort
#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int A[], int n, int left, int mid, int right){
	int n1 = mid-left;
	int n2 = right-mid;
	//分成左右两个数组 
	for(int i=0; i<n1; i++)
		L[i] = A[left+i];
	for(int i=0; i<n2; i++)
		R[i] = A[mid+i];
	L[n1]=R[n2]=SENTINEL;//将左右两个数组的边界设为无穷大
	int i=0,j=0;
	//保证数组的左边部分小于右边部分 
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i]<R[j])
			A[k]=L[i++];
		else
			A[k]=R[j++];
	} 
}

void mergeSort(int A[], int n, int left, int right){
	int mid=(left+right)/2;
	if(left+1<right){
		//无限二分割直至每个数组剩下一个或者两个数？ 
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		//自底而上进行归并 
		merge(A, n, left, mid, right);
	}
}

int main(){
	
	int n;
	cin>>n;
	int A[MAX];
	for(int i=0; i<n;i++)
		cin>>A[i];
	
	cnt = 0;
	mergeSort(A, n, 0, n);
	
	//这种输出方法似乎比我的牛逼？？ 
	for(int i=0;i<n;i++){
		if(i)
			cout<<" ";
		cout<<A[i];
	} 
	cout<<endl<<cnt<<endl; 
	
	return 0;
}
