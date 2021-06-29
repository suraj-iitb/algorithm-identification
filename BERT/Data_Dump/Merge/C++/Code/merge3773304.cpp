#include <bits/stdc++.h>
using namespace std;

#define INF (1000000000+1)

vector<int> L;
vector<int> R;
int cnt;

void merge( vector<int> &S, int left, int mid, int right )
{
	int n1 = mid - left;
	int n2 = right - mid;
	for( int i = 0; i < n1; i++ ) {
		L[i] = S[left + i];
	}
	for( int i = 0; i < n2; i++ ) {
		R[i] = S[mid + i];
	}
	int i = 0;
	int j = 0;
	L[n1] = INF;
	R[n2] = INF;
	for( int k = left; k < right; k++ ) {
		cnt++;
		if( L[i] <= R[j] ) {
			S[k] = L[i];
			i++;
		}
		else {
			S[k] = R[j];
			j++;
		}
	}
}

void sort( vector<int> &S, int left, int right )
{
	if( right - left <= 1 ) return;
	int mid = ( left + right ) / 2;
	sort( S, left, mid );
	sort( S, mid, right );
	merge( S, left, mid, right );
}

int main()
{
	int n;
	cin >> n;
	vector<int> S( n );
	L = vector<int>( n / 2 + 2 );
	R = vector<int>( n / 2 + 2 );
	for( int i = 0; i < n; i++ ) {
		cin >> S[i];
	}

	sort( S, 0, n );
	for( int i = 0; i < n; i++ ) {
		if( i ) cout << " ";
		cout << S[i];
	}
	cout << endl;
	cout << cnt << endl;
}

