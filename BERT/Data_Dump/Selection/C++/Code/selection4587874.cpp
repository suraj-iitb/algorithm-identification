#include <bits/stdc++.h>
using namespace std;

// 配列出力
template <typename T1, typename T2>
void arrayOutPut(vector<T1> A, T2 N){
	for(T2 i=0; i<N; i++){
		if(i>0) cout << " ";
		cout << A.at(i);
	}
}

// 選択ソート
int selectionSort(vector<int> &A,int &N){
	int minj;
	int buf;
	int count=0;
	for(int i=0; i<N-1; i++){
		minj = i;
		for(int j=i; j<N; j++){
			if(A.at(j) < A.at(minj)) minj=j;
		}
		buf = A.at(i);
		A.at(i) = A.at(minj);
		A.at(minj) = buf;
		if(minj != i) count++;
	}
	return count;
}


int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0; i<N; i++) cin >> A.at(i);
	int count;
	count = selectionSort(A, N);
	arrayOutPut(A, N);
	cout << endl;
	cout << count << endl;

}

