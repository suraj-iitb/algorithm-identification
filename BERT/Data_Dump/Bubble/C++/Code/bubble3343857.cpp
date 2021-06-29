#include<iostream>
using namespace std;

void BubbleSort( int a[], int N )
{
	int time = 0;
	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = N-1 ; j >= i+1 ; j-- )
		{
			if( a[j] < a[j-1])
			{
			   swap( a[j] , a[j-1] );
			   time++;
			}
			   
		}
	}
	for( int i = 0 ; i < N-1 ; i++ )
	    cout << a[i] << " ";
	cout << a[N-1] << endl;
	cout << time << endl;
}

int main()
{
	int N;
	cin >> N;
	int *A = new int [N];
	for( int i =0; i < N; i++ )
	{
		cin >> A[i];
	}
	BubbleSort( A , N );
	return 0;
}
