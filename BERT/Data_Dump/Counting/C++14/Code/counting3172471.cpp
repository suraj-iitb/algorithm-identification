#include<iostream>
#include<string>
using namespace std;
#define INFTY (int)(1e9+100)
#define MAX_N 2000100


void CountingSort(int A[], int B[], int k,int n){
	int C[k] = {};
	
	for(int i = 0; i < n; i++){
		C[A[i]]++;
	}
	for(int i = 0; i < k; i++){
		C[i] += C[i-1];
	}
	for(int i = n-1; i >= 0; i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	
}

int A[MAX_N], B[MAX_N];
int main(){
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>A[i];
	}
	
	CountingSort(A, B, 10002, n);
	for(int i = 0; i < n; i++){
		if(i)cout<<" ";
		cout<<B[i];
	}cout<<endl;
	return 0;
}
