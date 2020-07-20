#include <iostream>
using namespace std;

int main(){
	int N, count = 0;
	cin >> N;
	int *arr = new int[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < N-1; i++){
		for(int j = N-1; j >= i+1; j--){
			if(arr[j-1] > arr[j]){
				int tmp;
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
				count++;
			}
		}
	}

	for(int i = 0; i < N; i++){
		cout << arr[i];
		if(i != N-1) cout << " ";
	}

	cout << endl;
	cout << count << endl;

	return 0;
}
