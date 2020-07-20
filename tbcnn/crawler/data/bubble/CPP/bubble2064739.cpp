#include<iostream>

using namespace std;

int main(){
	int N; cin >> N;
	int A[100];
	int count = 0;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	int j = 0;
	bool flag = false;
	while (!flag){
		flag = true;
		for ( int i = N-1; i > j; i--){ 
			if (A[i] < A [i-1]){
				int tmp = A[i];
				A[i] = A[i-1];
				A[i-1] = tmp;
				count++;
				flag = false;
			}
		}
		j++;

	}
	for ( int i = 0; i < N; i++){
		cout << A[i] ;
		if(i != N-1){
			cout << " ";
		}
	}
	cout << endl;
	cout << count << endl;

	return 0;
}
