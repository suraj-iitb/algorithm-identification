#include <bits/stdc++.h>
#define INF 99999999
#define SENTINEL 2000000000
using namespace std;
typedef long long ll;
const int MAX_N=500010;
//用作合并的数组 
int L[MAX_N/2],R[MAX_N/2];
//合并所用比较次数 
int cnt;
//合并 
void merge(int a[],int n,int l,int mid,int r){
	//L,R数组长度 
	int n1=mid-l;
	int n2=r-mid;
	//更新排序好的数组到L,R 
	for(int i=0;i<n1;i++)
		L[i]=a[l+i];
	for(int i=0;i<n2;i++)
		R[i]=a[mid+i];
	L[n1]=R[n2]=SENTINEL;
	//由小到大合并到a 
	int i=0,j=0;
	for(int k=l;k<r;k++){
		cnt++;
		if(L[i]<=R[j])
			a[k]=L[i++];
		else
			a[k]=R[j++];
	} 
} 
//排序函数 
void mergeSort(int a[],int n,int l,int r){
	if(l+1<r){
		//分割数组为两部分递归排序 
		int mid=(l+r)/2;
		mergeSort(a,n,l,mid); 
		mergeSort(a,n,mid,r);
		//排序完后再合并 
		merge(a,n,l,mid,r);
	}
}

int main(){
	//n个元素的数组 
	int n; 
	int a[MAX_N];
	//初始化比较次数 
	cnt=0;
	//输入 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//排序 
	mergeSort(a,n,0,n);
	//输出 
	for(int i=0;i<n;i++) {
		if(i)
			cout<<' ';
		cout<<a[i]; 
	}
	cout<<endl;
	cout<<cnt<<endl; 
	return 0;
}

/*
样例
10
8 5 9 2 6 3 7 1 10 4
输出
1 2 3 4 5 6 7 8 9 10
34
*/
