#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int* T = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> T[i];
	}
	int num1 = 0;
	for(int i=0;i<num;i++)
	{
		for(int j=num-1;j>i;j--)
		{
			if (T[j] < T[j - 1])
			{
				swap(T[j], T[j - 1]);
				num1++;
			}
		}
	}
	for (int j = 0; j < num; j++)
	{
		cout << T[j] << (j == num - 1 ? '\n' : ' ');
	}
	cout << num1<<endl;
}
