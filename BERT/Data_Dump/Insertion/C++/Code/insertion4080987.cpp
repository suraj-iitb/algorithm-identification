#include <iostream>
using namespace std;

int main(){
	int n, temp;
	cin >> n;
	int* data = new int[n];
	for (int i=0; i<n; i++) {
		cin >> data[i];
	}
	for (int i=0; i<n; i++){
		int j=i;
		while (j>0 && data[i] < data[j-1]){
			j--;
		}
		temp = data[i];
		for (int m=i; m>j; m--) {
			data[m] = data[m-1];
		}
		data[j] = temp;
		
		for (int m=0; m<n-1; m++){
			cout << data[m] << " ";
		}
		cout << data[n-1] << endl;
	}
	return 0;
}
