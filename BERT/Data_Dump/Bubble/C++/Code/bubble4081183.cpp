#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i=0; i<n; i++){
		cin >> data[i];
	}
	int swapCount = 0;
	int temp;
	for (int i=0; i<n; i++){
		for (int j=n-1; j>i; j--){
			if (data[j] < data[j-1]){
				temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
				swapCount++;
			}
		}
	}
	for (int i=0; i<n-1; i++) {
		cout << data[i] << " ";
	}
	cout << data[n-1] << endl;
	cout << swapCount << endl;
	return 0;
}
