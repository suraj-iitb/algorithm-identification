#include <stdio.h>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print(int* A,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i != n - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}
void insert(int* A, int n)
{
	for (int i = 1; i < n; i++)
	{
		print(A, n);
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;

		}
		A[j + 1] = v;

	}
}
void bubble(int *A, int n)
{
	int flag = 1;
	int count=0;
	while (flag)
	{
		
		//print(A, n);
		flag = 0;
		for (int j = n - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1])
			{
				count++;
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = 1;
			}
		}
	}
	print(A, n);
	cout << count << endl;
}
int main()
{
	int n;
	cin >> n;
	
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	
	bubble(A, n);
	return 0;
}
