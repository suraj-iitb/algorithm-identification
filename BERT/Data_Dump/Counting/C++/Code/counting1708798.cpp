#include<iostream>
#include<vector>
using namespace std;

int out(vector<int> &A,int n){
	int i;
	for (i=0;i<=n-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[n-1] <<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,i,j;
	cin >> n;
	vector<int> A(n);
	for (i=0;i<n;i++){
		cin >> A[i];
	}
	
	const int k=10000;
	vector<int> C(k+1,0);
	vector<int> B(n);
	
	for (i=0;i<n;i++){
		C[A[i]]++;
	}
	
	for (j=1;j<k+1;j++){
		C[j]=C[j]+C[j-1];
	}
	
	for (i=n-1;i>-1;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
	
	out(B,n);
	return 0;
}
