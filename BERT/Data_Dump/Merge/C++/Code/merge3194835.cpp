#include<iostream>
using namespace std;
#define max 500000
#define sen 2000000000

int l[max/2+2],r[max/2+2];
int cnt;

void merge(int a[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++)l[i]=a[left+i];
	for(int i=0;i<n2;i++)r[i]=a[mid+i];
	l[n1]=r[n2]=sen;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(l[i]<=r[j])a[k]=l[i++];
		else a[k]=r[j++];
	}
}

void merso(int a[],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		merso(a,n,left,mid);
		merso(a,n,mid,right);
		merge(a,n,left,mid,right);
	}
}

int main(void){
	int a[max],n,i;
	cnt=0;
	
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	
	merso(a,n,0,n);
	
	for(i=0;i<n;i++){
		if(i)cout<<" ";
		cout << a[i];
	}
	cout <<endl;
	
	cout << cnt << endl;
	
	return 0;
}
