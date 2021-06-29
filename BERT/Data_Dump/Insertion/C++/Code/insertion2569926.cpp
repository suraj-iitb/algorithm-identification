#include <iostream>
#include <vector>
using namespace std;

void insertionSort( vector<int>& data, int n );
void trace( vector<int>& data, int n );

int main() {
	int n;

	cin >> n;
	vector<int> data(n);
	for( int i = 0; i < n; ++i ) {
		cin >> data.at(i);
	}
	trace( data, n );
	insertionSort( data, n );

}

void insertionSort( vector<int>& data, int n ) {
	for( int i = 1; i < n; ++i ) {
		int tmp = data.at( i );
		int j = i - 1;
		while( j >= 0 && tmp < data.at( j ) ) {
			data.at( j + 1 ) = data.at( j );
			j--;
		}
		data.at( j + 1 ) = tmp;
		trace( data, n );
	}
}

void trace( vector<int>& data, int n ) {
	for( int i = 1; i <= n; ++i ) {
		cout << data.at( i - 1 ) << ( ( i == n ) ? "\n" : " " );
	}
}
