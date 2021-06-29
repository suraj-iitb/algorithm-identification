#include <iostream>
using namespace std;
int main()
{
	int data[105],n,ans = 0,temp;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> data[i];
	for(int i = 1; i <= n; ++i)
	{
		int minj = i;
		for(int j = i; j <= n; ++j)
		{
			if(data[minj] > data[j])
				minj = j;
		}
		temp = data[i];
		data[i] = data[minj];
		data[minj] = temp;
		ans += (minj == i) ? 0 : 1;
	}
	cout << data[1];
	for(int i = 2; i <= n; ++i)
		cout << ' ' << data[i];
	cout << endl << ans << endl;
	return 0;
}
