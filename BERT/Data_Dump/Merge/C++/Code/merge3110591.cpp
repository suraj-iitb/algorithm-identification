#include<iostream>
using namespace std;
int L[250002],R[250002],cnt;
void merge(int A[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=R[n2]=2000000000;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	} 
}
int ms(int A[],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		ms(A,n,left,mid);
		ms(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}
int main(){
	int A[500000],n;
	cnt = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	ms(A,n,0,n);
	for(int i=0;i<n;i++){
		if(i){
			cout<<" ";
		}
		cout<<A[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}
