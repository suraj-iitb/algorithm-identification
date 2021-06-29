#include<iostream>

using namespace std;
static const int NMAX = 100;
static const int AMAX = 1000;

int main()
{
    int N = 0;
    int A[NMAX] = {0};
    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> A[i];
    }
    for(int m = 0 ; m < N ; m++)
	{
		cout << A[m];
		if(m == N-1)
		{
			cout << "\n";
		}
		else
		{
			cout << " ";
		}
	}
    for(int i = 1 ; i < N ; i++)
    {
        int temp = A[i];
        int j = i - 1; 
        for( ; j >= 0 && temp < A[j]; j--)
        {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
        for(int m = 0 ; m < N ; m++)
		{
			cout << A[m];
			if(m == N-1)
			{
				cout << "\n";
			}
			else
			{
				cout << " ";
			}
		}
    }
	return 0;
}
