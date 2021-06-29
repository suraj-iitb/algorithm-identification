#include <iostream>
using namespace std;

int main()
{	
	int arr[101];
	int m;
	int count = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	bool flag;
	flag = 1;
	while (flag) {
		flag = 0;
		for (int i = m - 1; i > 0; i--) {
			if (arr[i] < arr[i - 1]) {
				int t = arr[i-1];
				arr[i - 1] = arr[i];
				arr[i] = t;
				count++;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (i < m - 1)cout << arr[i] << " ";
		else cout << arr[i];

	}
	cout << endl;

	cout << count<<endl;

}
