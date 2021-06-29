#include <iostream>
using namespace std;

int main(){
	int numData;
	int a[100];
	cin >> numData;
	for ( int i = 0; i < numData; i ++){
		cin >> a[i];
	}
	for ( int i = 0; i < numData-1; i++){
		cout << a[i] << " ";
	}
	cout << a[numData - 1] << endl;
	for ( int i = 1; i < numData; i++ ){
		int v = a[i];
		int j = i-1;
		while ( a[j+1] < a[j] && j >= 0){
			a[j+1] = a[j];
			a[j] = v;
			j--;
		}
		for ( int i = 0; i < numData-1; i++){
			cout << a[i] << " ";
		}
		cout << a[numData - 1] << endl;
	}
	return 0;
}
