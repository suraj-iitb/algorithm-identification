#include <iostream>
using namespace std;

int main() {
	int n,A[2000010],B[2000010],C[2000010];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i+1];
		B[A[i+1]]++;
	}
	for(int i=1;i<2000010;i++){
		B[i]=B[i]+B[i-1];
	}
	for(int i=n;i>=1;i--){
		int j=A[i];
		int k=B[j];
		C[k-1]=j;
		B[j]--;
	}
	for(int i=0;i<n;i++){
		if(i){cout<< " ";}
		cout <<C[i];
	}
	cout <<endl;
}
