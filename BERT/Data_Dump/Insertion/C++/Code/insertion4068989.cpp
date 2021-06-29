#include <iostream>
#include <algorithm>
using namespace std; 
const int N = 105;
int a[N];
int n;
void print()
{
	for(int i = 0;i < n;++i)
	{
		cout << a[i];
		if(i != n-1)
			cout << " ";		
	}
	cout << endl;
}

void insertionSort()
{
	for(int i = 1;i < n;++i)
	{
		int v = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > v)
			a[j+1] = a[j],--j;
		a[j+1] = v;
		print();
	}
}

int main()
{
	cin >> n;
	for(int i = 0;i < n;++i)	cin >> a[i];
	print();
	insertionSort();
	return 0;
}
