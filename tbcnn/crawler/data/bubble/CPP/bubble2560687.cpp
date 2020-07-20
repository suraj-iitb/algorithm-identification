#include <iostream>
using namespace std;


void display(int A[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << A[i];
		if(i < n)
		{
			cout << " ";
		}
	}
	cout << endl;
}



int main(void)
{
	int N = 100;
	int n;
	int count = 0;
	int A[N];

	cin >> n;
	if(n < 1)
	{
		cout << "input Error!!" << endl;
		return 0;
	}

	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	int flag = 1;       	//BubbleSort
	while(flag)
	{
		flag = 0;
		int i = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = n; j >= (i+1); j--)
			{
				if(A[j] < A[j-1])
				{
					int k = A[j-1];
					A[j-1] = A[j];
					A[j] = k;
					count++;
					flag = 1;
				}
			}
		}
	}
	display(A, n);
	cout << count << endl;
	return 0;

}
