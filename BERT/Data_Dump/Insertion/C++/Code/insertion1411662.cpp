#include<iostream>
#include<vector>

using namespace std;

int main( )
{
	int n;
	cin>>n;
	vector<int> elems(n);
	for( int i=0; i<n; i++ ) {
		cin>>elems.at( i );
		cout<<elems.at( i );
		if( i< n-1 ) { cout<<' '; } else { cout<<'\n'; }
	}
	
	int key, j;
	for( int i=1; i<n; i++ ) {
		key = elems.at( i );
		j = i - 1;
		while( 0 <= j and key < elems.at( j ) ) {
			elems.at( j+1 ) = elems.at( j );
			j--;
		}
		elems.at( j+1 ) = key;
		
		for( int k=0; k<elems.size( ); k++ ) {
			cout<<elems.at( k );
			if( k < n-1 ) { cout<<' '; } else { cout<<'\n'; }
		}
	}
	
	return 0;
}
