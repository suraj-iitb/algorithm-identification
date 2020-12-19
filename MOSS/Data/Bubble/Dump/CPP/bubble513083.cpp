#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for( int i=0; i<n; i++ ){
		cin >> arr[i];
	}
	int count = 0;
	for( int i=0; i<n; i++ ){
		for( int j=n-2; j>=i; j-- ){
			if( arr[j] > arr[j+1] ){
				count++;
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	cout << arr[0];
	for( int i=1; i<n; i++ ){
		cout << " " << arr[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}
