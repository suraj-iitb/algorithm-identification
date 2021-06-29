#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
	int n, mini, temp, count=0;
	int A[MAX];

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for(int i = 0; i < n; i++)
	{
		mini = i;
		for(int j = i+1; j < n; j++)
		{
			if(A[mini] > A[j])
				mini = j;
		}
		if(i != mini)
		{
			count++;
			temp = A[mini];
			A[mini] = A[i];
			A[i] = temp;
		}
	}

	for(int i = 0; i < n-1; i++)
	{
		cout << A[i] << ' ';
	}
	cout << A[n-1] << endl;
	cout << count << endl;
	return 0;
}
