#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 110;
int a[MAX];
int sum;
void BubbleSort(int a[], int n)
{
	int flag = 1;	// 存在顺序相反的相邻元素 
	for(int i = 0; flag; ++ i)
	{
		flag = 0;
		for(int j = n - 1; j > i; -- j)
		{
			if(a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = 1;
				sum ++;
			}
		}
	}
} 

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++ i)
	{
		cin >> a[i];
	}
	
	BubbleSort(a, n);
	
	for(int i = 0; i < n; ++ i)
	{
		if(i == n - 1)
			cout << a[i];
		else
			cout << a[i] << " ";
	}
	cout << endl;
	cout << sum << endl;
	
	return 0;
}
