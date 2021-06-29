#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int A[n];
	auto output = [](int *A, int n){
		for(int i=0;i<n;++i){
			if(i)cout << " ";
			cout << A[i];
		}
		cout << endl;
	};
	for(auto &i:A)cin>>i;
	for(int j=1;j<n;++j){
		output(A, n);
		int key = A[j];
		int i = j - 1;
		while(i>=0&&A[i]>key){
			A[i+1] = A[i];
			--i;
		}
		A[i+1] = key;
	}
	output(A, n);
	return 0;
}

