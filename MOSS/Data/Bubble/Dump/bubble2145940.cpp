#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int cnt = 0;
	int a[128];

	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	bool flag = true;
	for (int i = 0; flag; i++){
		flag = false;
		for (int j = n - 1; j >= i + 1; j--){
			if (a[j] < a[j - 1]){
				swap(a[j], a[j - 1]);
				cnt++;
				flag = true;
			}
		}
	}

	
	for (int i = 0; i < n; i++){
		cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
	cout << cnt << endl;

	return 0;
}
