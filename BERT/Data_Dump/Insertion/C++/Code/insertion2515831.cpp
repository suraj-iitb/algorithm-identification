#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int length,i;
	cin >> length;
	vector<int>A;
	int element;
	for (int a = 0; a < length; a++)
	{
		cin >> element;
		A.push_back(element);
	}
	int key;
	for (i = 0; i < length; i++)
	{
		key = A[i];
		int j = i - 1;
		int k = i;
		for (; j >= 0; j--)
		{
			if (key < A[j])
			{
				for (; k > j; k--)
					A[k] = A[k - 1];
				A[j] = key;
			}
		}
		for (int a = 0; a < length; a++)
		{
			if (a > 0)
				cout << " ";
			cout << A[a];
		}
		cout << endl;
	}
	return 0;
}
