#include <iostream>
#include <algorithm>

using namespace std;

unsigned int d[101];

int main()
{
	unsigned int n;
	unsigned int num;
	bool flag = true;
	cin >> n;
	for (unsigned int i = 0; i < n; ++i)
		cin >> d[i];

	while (flag) {
		flag = false;
		for (unsigned int i = n-1; i > 0; --i) {
			if (d[i] < d[i-1]) {
				unsigned int x = d[i-1];
				d[i-1] = d[i];
				d[i] = x;
				++num;
				flag = true;
			}
		}
	}
	for (unsigned int i = 0; i < n - 1; ++i)
		cout << d[i] << " ";
	cout << d[n-1] << "\n" << num << endl;
	return 0;
}

