#include<iostream>
using namespace std;
int main()
{
	int A[100];
	int t,j,key,sum=0;
	cin >> t;
	for (int i = 0; i < t; i++)//输入t个数
	{
		cin >> A[i];
	}
	for (int i = 0; i < t; i++)//输出这t个数
	{
		cout << A[i] ;
		if (i != t - 1)cout << " ";

	}
	cout << endl;
	for (int i = 1; i < t; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key)//让数组从第i个数比到最开始的数
		{
			A[j + 1] = A[j];
			j--;
			A[j + 1] = key;
		}
		sum += 1;
		for (int i = 0; i < t; i++)
		{
			cout << A[i] ;
			if ( i != t - 1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}
