#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		int key = A[i];
		int j = i - 1;
		while(A[j] > key & j >= 0)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		for(int k = 0; k < N - 1; k++){
			cout << A[k] << " ";
		}
		cout << A[N-1] << endl;
	}
}
