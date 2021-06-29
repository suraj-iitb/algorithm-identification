#include <iostream>

using namespace std;

int main(){
	int N, i, j, k, key;
	cin >> N;
	int a[N];
	for(i = 0; i < N; i++){
		cin >> a[i];
	}

	cout << a[0];
	for(k = 1; k < N; k++){
		cout << ' ' << a[k];
	}
	cout << endl;

	for(i = 1; i < N; i++){
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;

		cout << a[0];
		for(k = 1; k < N; k++){
			cout << ' ' << a[k];
		}
		cout << endl;
	}

	return 0;
}
