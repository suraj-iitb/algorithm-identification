#include <iostream>
using namespace std;
#define m 500000
#define s 2000000000;
int L[m/2+2],R[m/2+2];
int cnt;
void merge(int A[],int a,int mid,int b){
	int n1 = mid - a;
	int n2 = b - mid;
	for(int i=0;i<n1;i++) L[i] = A[a+i];
	for(int i=0;i<n2;i++) R[i] = A[mid+i];
	L[n1] = R[n2] = s;
	int i = 0,j = 0;
	for(int k=a;k<b;k++){
		cnt++;
		if(L[i]<=R[j]) A[k] = L[i++];
		else A[k] = R[j++];
	}
}
void mergeSort(int A[],int a,int b)
{
	if(a+1<b){
		int mid = a + ((b-a)>>1);
		mergeSort(A,a,mid);
		mergeSort(A,mid,b);
		merge(A,a,mid,b);
	}
}
void print(int A[],int n){
	for(int i=0;i<n;i++){
		if(i) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
}
int main(){
	int A[m],n;
	cnt = 0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	mergeSort(A,0,n);
	print(A,n);
	cout<<cnt<<endl;
	return 0;
}
