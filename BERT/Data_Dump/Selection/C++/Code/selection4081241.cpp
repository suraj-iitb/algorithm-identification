#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i=0; i<n; i++){
		cin >> data[i];
	}
	int mini;
	int swapCount = 0;
	int temp;
	for (int i=0; i<n; i++){
		mini = i;
		for (int j=i; j<n; j++){
			if (data[j] < data[mini]){
				mini = j;
			}
		}
		if (mini != i) {
			temp = data[i];
			data[i] = data[mini];
			data[mini] = temp;
			swapCount++;
		}
	}
	for (int i=0; i<n-1; i++) {
		cout << data[i] << " ";
	}
	cout << data[n-1] << endl;
	cout << swapCount << endl;
	return 0;
}
