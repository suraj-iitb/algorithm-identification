#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >>N;
	int A[N];
	bool f = 1;
	for(int i=0 ; i<N ;i++){
		cin >>A[i];
	}
	int k=0;
	for(int i=0;f;i++){
		f = 0;
		for(int j = N-1; j>=i+1 ;j--){
			if(A[j]<A[j-1]){
				int t = A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				k++;
				f=1;
			}
		}
	}
	cout <<A[0];

	for(int i=1;i<N;i++){
		cout <<" "<<A[i];
	}
	cout <<endl<<k<<endl;

}
