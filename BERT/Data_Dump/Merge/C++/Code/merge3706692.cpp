#include<bits/stdc++.h>
static const int MAX = 1000000010;
using namespace std;
int A[500010],cnt;
void Merge(int A[],int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++){
		L[i] = A[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i] = A[mid+i];
	}
	L[n1]=MAX;
	R[n2]=MAX;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]){
			A[k] = L[i];
			i++;
			cnt++;
		}
		else{
			A[k] = R[j];
			j++;
			cnt++;
		}
	} 
}
void Merge_Sort(int A[],int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		Merge_Sort(A,left,mid);
		Merge_Sort(A,mid,right);
		Merge(A,left,mid,right);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	Merge_Sort(A,0,n);
	for(int i=0;i<n;i++){
		if(i<n-1)
			cout<<A[i]<<" ";
		else
			cout<<A[i]<<endl;
	}
	cout<<cnt<<endl;
	return 0;
} 
