#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=1e6;
int a[maxn];
int b[maxn];
int cnt;

void merge(int l,int mid,int r)
{
	int p1=l,p2=mid+1;//双指针
	int pos=l;//当前位置 
	while(p1<=mid&&p2<=r){
		cnt++;
		if(a[p1]<a[p2]){
			b[pos++]=a[p1++];
		}else{
			b[pos++]=a[p2++];
		}
	}
	while(p1<=mid){
		cnt++;
		b[pos++]=a[p1++];
	}
	while(p2<=r){
		cnt++;
		b[pos++]=a[p2++];
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
}

void merge_sort(int l,int r)
{
	if(l<r){
		int mid=(l+r)/2;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);
	}
}

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int n;
	cin>>n;
	cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	merge_sort(1,n);
	for(int i=1;i<=n;i++){
		if(i>1)cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}


