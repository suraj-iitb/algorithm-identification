#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	int A[1000], N;
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> A[i];

    for(int k = 0; k < N; k++)
	{
		cout << A[k];		
		if(k != N-1) cout << " ";
		else cout <<  "\n";
	}
		
	for(int i = 1; i < N; i++)
	{
		int j = i-1;
		int v = A[i];

		while(j >= 0 && A[j] > v)
		{
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = v;

		for(int k = 0; k < N; k++)
		{
			cout << A[k];
			if(k != N-1) cout << " ";
			else cout <<  "\n";
		}
	}

	return 0;
}
