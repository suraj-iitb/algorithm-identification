/////////////////////    答案    /////////////// 
/*
注意点：
1. 
*/
//----------------------自打1------------------ 
/*
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
long long cnt;
int a[50000010],l[25000010],r[25000010];
void merge(int a[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;++i){
		l[i]=a[left+i];
	}
	for(int i=0;i<n2;++i){
		r[i]=a[mid+i];
	}
	l[n1]=r[n2]=inf;
	int i=0,j=0;
	for(int k=left;k<right;++k){
		++cnt;
		if(l[i]<=r[j]){							//升(<)降(>),=控制稳定性 
			a[k]=l[i];
			++i;
		}else{
			a[k]=r[j];
			++j;
		}
	}
}
void mergesort(int a[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergesort(a,left,mid);
		mergesort(a,mid,right);
		merge(a,left,mid,right);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	mergesort(a,0,n);
	for(int i=0;i<n;++i){
		cout<<a[i]<<" \n"[i==n-1];
	} 
	cout<<cnt<<endl;
	return 0;
} 
*/
//---------------------标准答案--------------------
#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];
int cnt;

void merge(int A[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;++i){
		L[i]=A[left+i];
	}
	for(int i=0;i<n2;++i){
		R[i]=A[mid+i];
	}
	L[n1]=R[n2]=SENTINEL;
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

void mergeSort(int A[],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,n,left,mid);
		mergeSort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}

int main(){
	int A[MAX],n,i;
	cnt=0;
	
	cin>>n;
	for(int i=0;i<n;++i) cin>>A[i];
	
	mergeSort(A,n,0,n);
	
	for(int i=0;i<n;++i){
		if(i) cout<<" ";
		cout<<A[i];
	} 
	cout<<endl;
	
	cout<<cnt<<endl;
	
	return 0;
} 
