#include<iostream>
using namespace std;

void insertSort( int A[], int N )
{
	int time = 0;
	for( int i = 0 ; i < N; i++ )
	{
		int min = i;
		for( int j = i+1 ; j < N; j++ )
		{
			if( A[j] < A[min])
			   min = j;
		}
		if( min != i )
		{
		   int temp = A[i]; A[i] = A[min]; A[min] = temp;
		   time++; 
		}
		   
	}
	for( int i = 0 ; i < N-1 ; i++ )
	{
		cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << time << endl;
}

int main()
{
	int N;
	cin >> N;
	int *A = new int [N];
	for( int i = 0; i < N ; i++ )
	{
		cin >> A[i];
	}
	insertSort( A , N );
	return 0;
}
