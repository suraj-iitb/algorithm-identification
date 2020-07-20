#include <iostream>
using namespace std;

int main(void)
{
	int n, an[100];
	int cnt = 0;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> an[i];

	for(int i = 0; i <= n - 2; i++) {
		for(int j = n - 1; j - 1 >= i; j--) {
			if(an[j - 1] > an[j]) {
				int tmp = an[j - 1];
				an[j - 1] = an[j];
				an[j] = tmp;
				cnt++;
			}
		}
	}

	for(int i = 0; i < n; i++)
		cout << an[i] << (i == n - 1 ? '\n' : ' ');
	cout << cnt << endl;

	return 0;
}
