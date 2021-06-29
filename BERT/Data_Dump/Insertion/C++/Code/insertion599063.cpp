#include <iostream>
using namespace std;

int main(){
	int N,i,j,k;
	cin >> N;
	int A[100];

	for(i = 0; i < N; i++)
		cin >> A[i];

	for(i = 0; i < N - 1; i++)
		cout << A[i] << " ";
	cout << A[i++] << endl;

	for(i = 1; i < N; i++){
		j = i - 1;
		int key = A[i];
		while(j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			A[j] = key;
			j--;
		}
		for(k = 0; k < N - 1; k++)
			cout << A[k] << " ";
		cout << A[k++] << endl;
	}
}
