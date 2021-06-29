#include<bits/stdc++.h>
using namespace std;

int main(){

	int N;
	cin >> N;

	int A[101];
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	int count = 0;
	bool  flag = 1;
	while (flag){
		flag = 0;
		for (int i = N-1; i > 0; i--){
			if (A[i] < A[i - 1]){ 
				int t = A[i];  A[i] = A[i - 1]; A[i - 1] = t;
				flag = 1;
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++){
		printf("%d%c", A[i], i == N - 1 ? '\n' : ' ');
	}
	cout << count << endl;

	return 0;
}
