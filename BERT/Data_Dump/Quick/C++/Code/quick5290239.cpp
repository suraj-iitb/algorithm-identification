#include <bits/stdc++.h>
#define INF 99999999
#define SENTINEL 2000000000
using namespace std;
typedef long long ll;
const int MAX_N=100010;

struct Card{
	char suit;
	int v;
};

struct Card L[MAX_N/2],R[MAX_N/2];
//合并
void merge(struct Card a[],int n,int l,int mid,int r){
	int i,j,k;
	int n1=mid-l;
	int n2=r-mid;
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(i=0;i<n2;i++)
		R[i]=a[mid+i];
	L[n1].v=R[n2].v=SENTINEL;
	i=j=0;
	for(k=l;k<r;k++){
		if(L[i].v<=R[j].v)
			a[k]=L[i++];
		else
			a[k]=R[j++];
	} 
}
//归并排序 
void mergeSort(struct Card a[],int n,int l,int r){
	if(l+1<r){
		int mid=(l+r)/2;
		mergeSort(a,n,l,mid);
		mergeSort(a,n,mid,r);
		merge(a,n,l,mid,r); 
	} 
}
//以a[r]为基准，分割a数组 
int partition(struct Card a[],int n,int p,int r){
	int i,j;
	struct Card t,x;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
		if(a[j].v<=x.v){
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return i+1;
}
//快速排序 
void quickSort(struct Card a[],int n,int p,int r){
	int q;
	if(p<r){
		q=partition(a,n,p,r);
		quickSort(a,n,p,q-1);
		quickSort(a,n,q+1,r);
	}
}

int main(){
	//n张牌，牌面 
	int n,v;
	//牌数组，分别用来两种排序 
	struct Card a[MAX_N],b[MAX_N];
	//花色 
	char S[10];
	//stable标记 
	int f=1;
	//输入 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>S>>v;
		a[i].suit=b[i].suit=S[0];
		a[i].v=b[i].v=v;
	}
	//排序 
	mergeSort(a,n,0,n);
	quickSort(b,n,0,n-1);
	//比较两个排序函数的结果，判断是否稳定 
	for(int i=0;i<n;i++)
		if(a[i].suit!=b[i].suit)
			f=0;
	if(f)
		cout<<"Stable"<<endl;
	else
		cout<<"Not stable"<<endl;
	for(int i=0;i<n;i++)
		cout<<b[i].suit<<' '<<b[i].v<<endl;
	return 0;
}

/*
样例
6
D 3
H 2
D 1
S 3
D 2
C 1
输出
Not stable
D 1
C 1
D 2
H 2
D 3
S 3
*/
