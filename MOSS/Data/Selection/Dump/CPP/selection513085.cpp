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
		int mini = i;
		for( int j=i+1; j<n; j++ ){
			if( arr[mini] > arr[j] ){
				mini = j;
			}
		}
		if( i != mini ){
			int tmp = arr[mini];
			arr[mini] = arr[i];
			arr[i] = tmp;
			count++;
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
