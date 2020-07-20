#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int N;
	int cnt = 0;
	cin >> N;
	int *A = new int[N];
	for( int i = 0; i < N; i++ )
		cin >> A[i];

	// バブルソート
	for( int i = 0; i < N; i++ )
	{
		for( int j = N - 1; j > i; j-- )
		{
			if( A[j - 1] > A[j] )
			{
				swap( A[j - 1], A[j] );
				cnt++;
			}
		}
	}

	for( int i = 0; i < N; i++ )
	{
		if( i ) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << cnt << endl;
	return 0;
}
