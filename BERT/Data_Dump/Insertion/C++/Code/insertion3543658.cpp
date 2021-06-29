#include <iostream>
using namespace std;
int data[105];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> data[i];
	cout << data[1];
	for(int j = 2; j <= n; ++j)
		cout << ' ' << data[j];
	cout << endl;
	for(int i = 2; i <= n; ++i)
	{
		int v = data[i];
		int j = i-1;
		while((j > 0) && (data[j] > v))
		{
			data[j+1] = data[j];
			--j;
		}
		data[j+1] = v;
		cout << data[1];
		for(int j = 2; j <= n; ++j)
			cout << ' ' << data[j];
		cout << endl;
	}
	return 0;
}
