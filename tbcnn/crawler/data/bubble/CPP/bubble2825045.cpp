#include <iostream>
using namespace std;


int bubbleSort(int a[], int n) {
	int flag = 1, cnt = 0;
	
	while (flag) {
		flag = 0;
		
		for (int j = n - 1; 1 <= j; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				cnt++;
				flag = 1;
			}
		}
	}

	return cnt;
}


int main()
{
	int n, t, a[100];
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	t = bubbleSort(a, n);

	for (int i = 0;i < n;i++) {
		cout << a[i];
		if (i != n - 1) cout << " ";
		else cout << endl;
	}

	cout << t << endl;

    return 0;
}

