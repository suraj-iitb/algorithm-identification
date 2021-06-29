#include<bits/stdc++.h>
using namespace std;
#define max 500000
int A[max],L[max],R[max];
int n,totalcount;
void merger(int *A,int left,int mid,int right) {
	int n1=mid-left;
	int n2=right-mid;
	int i;
	for(i=0; i<n1; i++){
        L[i]=A[left+i];
	}
	for(i=0; i<n2; i++){
        R[i]=A[mid+i];
	}
	L[n1] = 1000000000;
	R[n2] = 1000000000;
	i=0;
	int j=0;
	int k;
	for(k=left; k < right; k++) {
	    
		if(L[i]<=R[j])
			A[k]=L[i++];
		else
			A[k]=R[j++];
		totalcount = totalcount + 1;
	}

}
void merge_sorts(int *A,int left,int right) {
    
	if(left+1<right) {
		int mid=(left+right)/2;
		merge_sorts(A,left,mid);
		merge_sorts(A,mid,right);
		merger(A,left,mid,right);
	}
}
int main() {
	int i;
	cin>>n;
	for(i=0; i<n; i++){
		cin>>A[i];
	}
	merge_sorts(A,0,n);
	for(i=0; i<n; i++) {
	    
		if(i!=(n-1)){
                cout <<A[i]<<" ";
            }
            else{
                cout << A[i];
            }
	}
	cout<<endl;
	cout<<totalcount <<endl;
	return 0;
}

