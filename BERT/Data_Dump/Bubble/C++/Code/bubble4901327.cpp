
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int count = 0;
	int i,j;
	const int MAX = 100;
	int arr[MAX];

	int flag;

	int n;

	int temp;

	cin>>n;

	for(i = 0;i < n;i++)
	{
		cin>>arr[i];
	}

	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

	for(i = 0;i < n;i++)
	{
		cout<<arr[i];
		if(i != n - 1)
			cout<<" ";
	}

	cout<<endl<<count<<endl;

}
