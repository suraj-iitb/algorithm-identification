#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int bubbleSort(vector<int> &A, int n){
	int res = 0;
	while(n-1){
		for(int i = 0; i < n-1; i++){
			if(A[i] > A[i+1]) {
				swap(A[i], A[i+1]);
				res++;
			}
		}
		n--;
	}
	return res;
}
				




int main(){
	int n; cin >> n;
	vector<int> A(120);
	for(int i = 0; i < n; i++) cin >> A[i];
	int res = bubbleSort(A, n);
	for(int i = 0; i < n; i++){
		if(i == n-1) cout << A[i] << endl;
		else cout << A[i] << " ";
	}
	cout << res << endl;	

	return 0;
}

