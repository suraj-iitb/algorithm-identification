#include<bits/stdc++.h>
using namespace std;
#define max 500002
int a[max],n,cnt;
int l[max/2+2],r[max/2+2];
void merge(int *a,int left,int mid,int right) {
	int n1=mid-left,n2=right-mid,i;
	for(i=0; i<n1; i++)l[i]=a[left+i];
	for(i=0; i<n2; i++)r[i]=a[mid+i];
	l[n1]=r[n2]=2000000000;
	i=0;
	int j=0,k;
	for(k=left; k<right; k++) {
		if(l[i]<=r[j])
			a[k]=l[i++];
		else
			a[k]=r[j++];
		cnt++;
	}

}
void merges(int *a,int left,int right) {
	if(left+1<right) {
		int mid=(left+right)/2;
		merges(a,left,mid);
		merges(a,mid,right);
		merge(a,left,mid,right);
	}
}
int main() {
	int i;
	cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i];
	merges(a,0,n);
	for(i=0; i<n; i++) {
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<cnt;
	cout<<endl;
	return 0;
}
