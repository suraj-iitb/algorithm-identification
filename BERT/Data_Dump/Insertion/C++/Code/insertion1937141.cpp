#include<iostream>
#include<vector>
using namespace std;

vector<int> Sort(vector<int> A, int i){
	int j = i - 1;
	while(j >= 0 && A[j] > A[j+1]){
		int v = A[j+1];
		A[j+1] = A[j];
		A[j] = v;
		j--;
	}
	return A;
}

int main(){
	int N;
	cin >> N;
	vector<int> A;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}
	for(int i = 0; i < N; i++){
		A = Sort(A, i);
		for(int j = 0; j < N-1; j++) cout << A[j] << ' ';
		cout << A[N-1] << endl;
	}
	return 0;
}
