#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *A=new int[n],*B=new int[n],C[10001]={0};
	for(int i=0;i<n;++i){
		cin>>A[i];
		++C[A[i]];
		B[i]=0;
	}
	for(int i=1;i<10001;++i){
		C[i]+=C[i-1];
	}
	for(int i=n-1;i>=0;--i){
		B[--C[A[i]]]=A[i];
	}
	for(int i=0;i<n-1;++i){
		cout<<B[i]<<" ";
	}
	cout<<B[n-1]<<endl;
	return 0;
}

