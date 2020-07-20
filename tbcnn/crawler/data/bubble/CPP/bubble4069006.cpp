#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int a[N];
int res = 0;
int n;
void bubbleSort()
{
	int l = n;
	for(int i = 0;i < n;++i)
	{
		for(int j = 0;j < n-1;++j)
		{
			if(a[j] > a[j+1])
			{
				++res;
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 0;i < n;++i)
		cin >> a[i];
	bubbleSort();
	for(int i = 0;i < n;++i)
	{
		cout << a[i];
		if(i != n-1)
			cout << " ";
	}
	cout << endl;
	cout << res << endl;
	return 0;
}
