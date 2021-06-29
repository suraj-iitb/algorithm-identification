#include<iostream>

using namespace std;

int main(){
	int N, i, j, key;
	cin >> N;
	int A[N];
	for(i = 0; i < N; i++)
		cin >> A[i];

	for(i = 0; i < N; i++){
		key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
		for(int k = 0; k < N; k++){
		if(k > 0)
			cout << " ";
		cout << A[k];
		}
		cout << endl;
	}

	return 0;
}
