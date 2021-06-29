#include<bits/stdc++.h>
#define ll long long
static const int MAX=5E5+2;
static const int M=1E9+2; 
using namespace std;
int a[MAX],l[MAX],r[MAX];
int cnt;
void merge(int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) l[i]=a[left+i];
	l[n1]=M;
	for(int i=0;i<n2;i++) r[i]=a[mid+i];
	r[n2]=M;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(l[i]<=r[j]) a[k]=l[i++];
		else a[k]=r[j++];
	}	
}
void mergesort(int left,int right)
{
	if(left+1<right){
		int mid=(left+right)/2;
		mergesort(left,mid);
		mergesort(mid,right);
		merge(left,mid,right);
	}
 } 
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i]; 
	mergesort(0,n);
	for(int i=0;i<n;i++){
	    if(i) cout<<" ";
	    cout<<a[i];
	}
	cout<<endl<<cnt<<endl;
}
