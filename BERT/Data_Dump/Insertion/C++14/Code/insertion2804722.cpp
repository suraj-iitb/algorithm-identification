#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, A[110], v, j;
	cin>>N;
	for(int i = 0; i < N; i++) cin>>A[i];
	for(int k = 0; k < N; k++){
		cout<<A[k];
		if(k < N - 1)cout<<" ";
	}
	cout<<endl;
	
	for(int i = 1; i < N; i++){
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v){	
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(int k = 0; k < N; k++){
			cout<<A[k];
			if(k < N - 1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
