#include<iostream>
using namespace std;
#define MAX 500000
#define SEN 2000000000
int L[MAX/2+2],R[MAX/2+2];
int cnt;
void merge(int a[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=a[left+i];
	for(int i=0;i<n2;i++) R[i]=a[mid+i];
	L[n1]=R[n2]=SEN;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i]<=R[j]){
			a[k]=L[i++];
		}else{
			a[k]=R[j++];
		}
	}
}
void mergesort(int a[],int n,int left,int right){
	if(left+1<right){
		int mid=(right+left)/2;
		mergesort(a,n,left,mid);
		mergesort(a,n,mid,right);
		merge(a,n,left,mid,right);
	}
}
int main(){
	int a[MAX],n,i;
	cnt=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	mergesort(a,n,0,n);
	for(i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}