#include <iostream>
using namespace std;

int selectionSort(int a[], int N){
	int idx = 0;
	for ( int i = 0; i < N-1; i ++){
		int minj = i;
		for ( int j = i + 1; j < N; j++){
			if ( a[j] < a[minj] ) minj = j;
		}
		if ( minj != i ){
			int tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			idx++;
		}
	}
	return idx;
}

int main(){
	int N;
	int a[100];
	cin >> N;
	for ( int i = 0; i < N; i++) cin >> a[i];

	int idx = selectionSort( a, N);

	for ( int i = 0; i < N; i++){
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << idx << endl;
	return 0;
}
