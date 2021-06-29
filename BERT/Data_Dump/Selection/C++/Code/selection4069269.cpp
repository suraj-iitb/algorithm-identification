#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
int a[N];
int res = 0,n;
void insertionSort()
{
	for(int i = 0;i < n;++i)
	{
		int minv = a[i],pos = i;
		for(int j = i+1;j < n;++j)
		{
			if(a[j] < minv)
				minv = a[j],pos = j;
		}
		if(minv != a[i])
			swap(a[pos],a[i]),++res;
	}
}
int main()
{
	cin >> n;
	for(int i = 0;i < n;++i)
		cin >> a[i];
	insertionSort();
	for(int i = 0;i < n;++i)
	{
		cout << a[i];
		if(i != n-1)
			cout << " ";
	}
	cout <<  endl <<res << endl;
	return 0;
} 
