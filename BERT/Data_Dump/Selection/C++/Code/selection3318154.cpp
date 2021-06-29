#include <iostream>
#include <algorithm>

using namespace std;

unsigned int d[101];

int main()
{
	unsigned int n;
	unsigned int num;
	cin >> n;
	for (unsigned int i = 0; i < n; ++i)
		cin >> d[i];

	for (unsigned int i = 0; i < n; ++i) {
		unsigned int minj = i;
		for (unsigned int j = i+1; j < n; ++j) {
			if (d[j] < d[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			unsigned int t = d[i];
			d[i] = d[minj];
			d[minj] = t;
			++num;
		}
	}
	for (unsigned int i = 0; i < n - 1; ++i)
		cout << d[i] << " ";
	cout << d[n-1] << "\n" << num << endl;
	return 0;
}
     
