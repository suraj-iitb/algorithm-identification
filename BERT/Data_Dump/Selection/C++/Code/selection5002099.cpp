#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int N; cin >> N;
	vector<int> A(110);
	int count = 0;
	for(int i = 0; i < N; i++) cin >> A[i];

	for(int i = 0; i < N; ++i){
		int min_index = i;
		for(int j = min_index; j < N; ++j){
			if(A[j] < A[min_index]){
				min_index = j;
			}
		}
		swap(A[i], A[min_index]);
		if(i!=min_index) count++;
	}

	for(int i = 0; i < N; i++){
		if(i!=N-1) cout << A[i] << " ";
		else cout << A[i] << endl;
	}
	cout << count << endl;

}

