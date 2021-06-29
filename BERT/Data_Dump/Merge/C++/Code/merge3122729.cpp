#include<bits/stdc++.h>
using namespace std;
int l[10000000];
int r[10000000];
int cnt = 0;
void merge(int n,int t[],int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right -mid;
	for(int i = 0;i<n1;i++) l[i] = t[left+i];
	for(int i = 0;i<n2;i++) r[i] = t[mid+i];
	l[n1] = r[n2] = 99999999999;
	int i = 0,j = 0;
	for(int k = left;k<right;k++){
		cnt++;
		if(l[i] <=r[j]){
			t[k] = l[i];
			i++;
		}else{
			t[k] = r[j];
			j++;
		}
	}
}
void mergesort(int t[],int n,int left,int right){
	if(left +1<right){
	int mid = (left + right)/2;
	mergesort(t,n,left,mid);
	mergesort(t,n,mid,right);
	merge(n,t,left,mid,right);
	}
}
int main(){
	int n;
	cin>>n;
	int t[n];
	for(int  i = 0;i<n;i++){
		cin>>t[i];
	}
	mergesort(t,n,0,n);
	for(int i = 0;i<n;i++){
		if(i)cout<<" ";
		cout<<t[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}
