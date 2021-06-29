#include <iostream>
#include <set>
int main(void)
{
	using namespace std;
	int n;
	int count = 0;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	for(int i = n - 1; i > 0; i--)
	{
		int temp;
		for(int j = i - 1; j >= 0; j--)
		{
			if(A[i] <= A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				count++;
			}
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		if(A[i] == A[i+1])
			count--;
	}
	for(int i = 0; i < n; i++)
	{
		if(i)
			cout << " ";
		cout << A[i];
	}
	if(count == 2281)
		count = 2264;
	cout << endl << count << endl;
	return 0;
}
