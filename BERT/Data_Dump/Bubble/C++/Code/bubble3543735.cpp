#include <iostream>
using namespace std;
int main()
{
	int data[105],n,ans = 0,temp;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> data[i];
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i = n; i >= 2; --i)
		{
			if(data[i] < data[i-1])
			{
				temp = data[i];
				data[i] = data[i-1];
				data[i-1] = temp;
				++ans;
				flag = true;
			}
		}
	}
	cout << data[1];
	for(int i = 2; i <= n; ++i)
		cout << ' ' << data[i];
	cout << endl << ans << endl;
	return 0;
}
