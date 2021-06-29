#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	const int MAX = 100;
	int arr[MAX], i = 0, j = 0, mini = 0, count = 0, temp, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		mini = i;//寻找最小元素的下标
		for (j = i + 1; j < n ; j++)
		{
			if (arr[mini] > arr[j])
			{
				mini = j;
			}
		}
		if (i != mini){
			swap(arr[i], arr[mini]);
			count++;
		}
	}
/*
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << (i != n ? " " : "");
	}
	cout << endl << count << endl;
*/
	for(i = 0;i < n;i++)
	{
		cout<<arr[i];
		if(i != n - 1)
			cout<<" ";
	}
	cout<<endl<<count<<endl;
}
