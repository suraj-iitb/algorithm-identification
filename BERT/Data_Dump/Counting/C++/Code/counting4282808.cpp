#include<iostream>
using namespace std;
const int AMAX=10005;
const int MAX=2000005;
int C[AMAX]={0},A[MAX],B[MAX];
void CountingSort(int A[],int B[],int n){
	for(int i=0;i<n;i++)C[A[i]]++;
	for(int i=1;i<AMAX;i++){
		C[i]+=C[i-1];
	}
	for(int i=n-1;i>=0;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	CountingSort(A,B,n);
	for(int i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<B[i];
	}
	cout<<endl;
}
