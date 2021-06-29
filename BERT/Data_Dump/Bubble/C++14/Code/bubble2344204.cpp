//??????????????????
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int> A(N);
	for(int i=0; i<N; ++i){
		cin>>A[i];
	}
	
	int kaisuu=0;
	for(int i=0;i<N-1;++i){
		for(int j=0;j<N-1-i;++j){
			if(A[j]>A[j+1]){
				swap(A[j],A[j+1]);
				kaisuu++;
			}
		}
	}

	for(int i=0; i<N-1;++i){
		cout<<A[i]<<" ";
	}
	cout<<A[N-1]<<endl;
	cout<<kaisuu<<endl;
}
