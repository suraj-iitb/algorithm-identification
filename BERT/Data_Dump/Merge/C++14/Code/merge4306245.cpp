#include<iostream>
#include<algorithm>
#define inf 1000000001
using namespace std;
int ans;
void merge(int A[],int left,int mid,int right){
int n1=mid-left;
int n2=right-mid;
	int L[n1+1],R[n2+1];
	int i,k,j;
	for(i=0;i<n1;i++)
	L[i]=A[left+i];
	for(i=0;i<n2;i++)
	R[i]=A[mid+i];
	L[n1]=inf;
	R[n2]=inf;
	i=0;j=0;
	for(k=left;k<right;k++){
		ans++;
		if(L[i]<=R[j]){
		A[k]=L[i];
			i++;
		}
		else{
		A[k]=R[j];
			j++;
		}
		
		
	}
	
}
void Msort(int A[],int left,int right){
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		Msort(A,left,mid);
		Msort(A,mid,right);
		merge(A,left,mid,right);
	}
}
void print(int n,int a[]){
int i;
for(i=0;i<n-1;i++)
printf("%d ",a[i]);
printf("%d\n",a[n-1]);
}
main(){
	int a[500000],n,i;
	ans=0;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	Msort(a,0,n);
	print(n,a);
	cout<<ans<<endl;
	return 0;
}

