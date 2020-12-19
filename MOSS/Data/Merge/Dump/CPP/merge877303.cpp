#include<cstdio>
#include<iostream>

#define NMAX 500000
#define SENTINEL 1000000001

int cnt=0;

using namespace std;

void merge(int A[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	int L[NMAX],R[NMAX];
	for(int i=0;i<=n1-1;i++){
		L[i]=A[left+i];
	}
	for(int i=0;i<=n2-1;i++){
		R[i]=A[mid+i];
	}
	L[n1]=SENTINEL;
	R[n2]=SENTINEL;
	int i=0,j=0;
	for(int k=left;k<=right-1;k++){
		cnt++;
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}

void merge_sort(int A[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		merge_sort(A,left,mid);
		merge_sort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(void){

	int n;
	int A[NMAX];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	merge_sort(A,0,n);
	for(int i=0;i<n-1;i++){
		cout<<A[i]<<" ";
	}
	cout<<A[n-1]<<endl;
	cout<<cnt<<endl;

    return 0;
}
