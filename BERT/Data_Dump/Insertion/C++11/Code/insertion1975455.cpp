#include <bits/stdc++.h>
using namespace std;


int main(void){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	for(int j=0;j<N;j++){
		cout << A[j];
		if(j != N-1)cout << " ";
	}cout << endl;

	for(int i=1;i<=N-1;i++){
		int v = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		for(int j=0;j<N;j++){
			cout << A[j];
			if(j != N-1)cout << " ";
		}cout << endl;
	}

	return 0;
}
