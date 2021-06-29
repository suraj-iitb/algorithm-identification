#include <iostream>
#include <cstdlib>
#include <vector>
//数列 A を読み込み、バブルソートで昇順に並び変え出力するプログラムを作成してください。また、バブルソートで行われた要素の交換回数も報告してください。
using namespace std;
int main(){
	int n, count = 0;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		A[i] = num;
	}
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = n - 1; i >= 1; i--){
			if(A[i] < A[i - 1]){
				flag = true;
				int tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				count++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << A[i];
		if(i != n - 1) cout << ' ';
	}
	cout << endl;
	cout << count << endl;
}

