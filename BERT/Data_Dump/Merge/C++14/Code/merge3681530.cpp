#include <iostream>
using namespace std;
#define inf 2000000000

int A[500010],n,L[500010/2+2],R[500010/2+2],cnt=0;

void merge(int left,int right, int mid){
	int n1=mid-left;
	int n2=right -mid;
	for(int i=0;i<n1;i++){L[i]=A[left+i];}
	for(int i=0;i<n2;i++){R[i]=A[mid+i];}
	L[n1]=R[n2]=inf;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt ++;
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
		}
	}
}

void mergesort(int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergesort(left,mid);
		mergesort(mid,right);
		merge(left,right,mid);
	}
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	mergesort(0,n);
	for(int i=0;i<n;i++){
		if(i){cout<< " ";}
		cout <<A[i];
	}
	cout <<endl<<cnt<<endl;
}
