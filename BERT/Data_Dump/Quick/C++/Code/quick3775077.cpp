#include <bits/stdc++.h>
using namespace std;

#define INF (1000000000+1)

typedef struct {
	char a;
	int v;
} card;

vector<card> L;
vector<card> R;

void merge( vector<card> &A, int left, int mid, int right )
{
	int n1 = mid - left;
	int n2 = right - mid;
	for( int i = 0; i < n1; i++ ) {
		L[i] = A[left + i];
	}
	for( int i = 0; i < n2; i++ ) {
		R[i] = A[mid + i];
	}
	L[n1].v = INF;
	R[n2].v = INF;
	int i = 0;
	int j = 0;
	for( int k = left; k < right; k++ ) {
		if( L[i].v <= R[j].v ) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

void msort( vector<card> &A, int left, int right )
{
	if( right - left <= 1 ) return;
	int mid = ( right + left ) / 2;
	msort( A, left, mid );
	msort( A, mid, right );
	merge( A, left, mid, right );
}

int partition( vector<card> &A, int p, int r )
{
	card x = A[r];
	int i = p - 1;
	for( int j = p; j < r; j++ ) {
		if( A[j].v <= x.v ) {
			i++;
			swap( A[i], A[j] );
		}
	}
	swap( A[i + 1], A[r] );
	return i + 1;
}

void quick( vector<card> &A, int p, int r )
{
	if( p >= r ) return;
	int q = partition( A, p, r );
	quick( A, p, q - 1 );
	quick( A, q + 1, r );
}

int main()
{
	int n;
	cin >> n;
	vector<card> A( n );
	vector<card> B( n );
	L = vector<card>( n / 2 + 2 );
	R = vector<card>( n / 2 + 2 );
	for( int i = 0; i < n; i++ ) {
		cin >> A[i].a >> A[i].v;
		B[i] = A[i];
	}

	quick( A, 0, n - 1 );
	msort( B, 0, n );
	int s = 0;
	for( int i = 0; i < n; i++ ) {
		if( A[i].a != B[i].a ) {
			s = 1;
			break;
		}
	}
	string ans = "Stable";
	if( s ) ans = "Not stable";
	cout << ans << endl;
	for( int i = 0; i < n; i++ ) {
		cout << A[i].a << " " << A[i].v << endl;
	}
}

